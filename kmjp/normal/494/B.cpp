#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

struct RollingHash {
    static const ll mo0=1000000007,mo1=1000000009;
    static const ll mul0=10009,mul1=10007;
    static const ll add0=1000010007, add1=1003333331;
    string s; int l;
    vector<ll> hash_[2],pmo_[2],pmor_[2];
    void init(string s) {
        this->s=s; l=s.size(); int i,j;
        hash_[0].push_back(0); pmo_[0].push_back(1);
        hash_[1].push_back(0); pmo_[1].push_back(1);
        FOR(i,l) pmo_[0].push_back(pmo_[0].back()*mul0%mo0);
        FOR(i,l) pmo_[1].push_back(pmo_[1].back()*mul1%mo1);
        FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
        FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
    }
    pair<ll,ll> hash(int l,int r) { // s[l..r]
        pair<ll,ll> p=make_pair(hash_[0][r+1]+(mo0-hash_[0][l]*pmo_[0][r+1-l]%mo0),
                                hash_[1][r+1]+(mo1-hash_[1][l]*pmo_[1][r+1-l]%mo1));
        if(p.first>=mo0) p.first-=mo0;
        if(p.second>=mo1) p.second-=mo1;
        return p;
    }
};

string S,T;
int LS,LT;
ll mo=1000000007;
RollingHash sh,th;
int ok[100010];
ll dp[100010];
ll sum[100010];
ll sum2[100010];



void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S>>T;
    LS=S.size();
    LT=T.size();
    
    sh.init(S);
    th.init(T);
    pair<ll,ll> ph=th.hash(0,LT-1);
    FOR(i,LS-(LT-1)) ok[i]=ph==sh.hash(i,i+(LT-1));
    
    dp[0]=sum[0]=sum2[0]=1;
    int lo=-1;
    FOR(i,LS) {
        if(i-(LT-1)>=0 && ok[i-(LT-1)]) lo=i-(LT-1);
        
        if(lo>=0) dp[i+1]=sum2[lo]%mo;
        sum[i+1]=(sum[i]+dp[i+1])%mo;
        sum2[i+1]=(sum2[i]+sum[i+1])%mo;
    }
    cout<<(sum[LS]+(mo-1))%mo<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}