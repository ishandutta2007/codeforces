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

vector<int> Zalgo(string s) {
    int l=-1,r=-1,i;
    vector<int> v;
    v.push_back(s.size());
    for(i=1;i<s.size();i++) {
        if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
        else {
            l=i; r=(i>r)?i:(r+1);
            while(r<s.size() && s[r-i]==s[r]) r++;
            v.push_back((r--)-l);
        }
    }
    return v;
}

int L,K;
string S,T;
RollingHash rh;
int LL[1001000];
int SS[2001000];
vector<int> Z;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>L>>K>>S;
    while(S.size()<L) S+=S;
    S=S.substr(0,L);
    
    rh.init(S);
    Z=Zalgo(S);
    Z.resize(Z.size()+1000500);
    
    for(x=1;x*K<=L;x++) {
        int ng=0;
        FOR(y,K-1) if(rh.hash(y*x,y*x+x-1)!=rh.hash((y+1)*x,(y+1)*x+(x-1))) ng++;
        if(ng==0) LL[x*K-1]=x;
    }
    ll t=0;
    FOR(i,L) if(LL[i]) {
        SS[i]++;
        SS[min(i+LL[i]+1,i+1+Z[i+1])]--;
    }
    
    x=0;
    T=S;
    FOR(i,L) {
        x+=SS[i];
        T[i]=x?'1':'0';
    }
    cout<<T<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}