#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

struct RollingHash {
    static const ll mo0=1000000007,mo1=1000000009;
    static const ll mul0=10009,mul1=10007;
    static const ll add0=1000010007, add1=1003333331;
    static vector<ll> pmo[2];
    string s; int l; vector<ll> hash_[2];
    void init(string s) {
        this->s=s; l=s.size(); int i,j;
        hash_[0]=hash_[1]=vector<ll>(1,0);
        if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
        FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
        FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
    }
    pair<ll,ll> hash(int l,int r) { // s[l..r]
        if(l>r) return make_pair(0,0);
        while(pmo[0].size()<r+2)
            pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
        return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
                         (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
    }
    pair<ll,ll> hash(string s) { init(s); return hash(0,s.size()-1); }
    static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) 
        while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
        return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
    }
};
vector<ll> RollingHash::pmo[2];

int LS,LT;
string S,T;
pair<ll,ll> SH[26][202000],TH[26];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>LS>>LT>>S>>T;
    
    FOR(x,26) {
        s = string(LS,'0');
        FOR(i,LS) if(S[i]=='a'+x) s[i]='1';
        RollingHash sh;
        sh.init(s);
        FOR(i,LS-LT+1) SH[x][i]=sh.hash(i,i+LT-1);
        
        s = string(LT,'0');
        FOR(i,LT) if(T[i]=='a'+x) s[i]='1';
        sh.init(s);
        TH[x]=sh.hash(0,LT-1);
    }
    
    vector<int> R;
    FOR(i,LS-LT+1) {
        int vis[26]={};
        int ng=0;
        FOR(x,26) if(vis[x]==0) {
            FOR(y,26) if(vis[x]+vis[y]==0) {
                if(TH[y]==SH[x][i] && TH[x]==SH[y][i]) vis[x]=vis[y]=1;
            }
            if(vis[x]==0) {
                ng=true;
                break;
            }
        }
        if(!ng) R.push_back(i+1);
    }
    
    _P("%d\n",R.size());
    FORR(r,R) _P("%d ",r);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}