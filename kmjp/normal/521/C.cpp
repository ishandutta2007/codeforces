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

ll mo=1000000007;
int N,K;
string S;
ll num[101000];
ll p10[101000];

ll combi(ll N_, ll C_) {
    const int NUM_=400001;
    static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
    if (fact[0]==0) {
        inv[1]=fact[0]=factr[0]=1;
        for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
        for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
    }
    if(C_<0 || C_>N_) return 0;
    return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>K>>S;
    
    p10[0]=1;
    FOR(i,N) p10[i+1]=p10[i]*10%mo;
    FOR(i,N) num[N-1-i]+=S[i]-'0';
    
    ll ret=0;
    for(i=N-1;i>=0;i--) {
        ret += num[i+1]*p10[i]%mo*combi(N-2-i,K-1) % mo;
        ret += num[i]*p10[i]%mo*combi(N-1-i,K) % mo;
        num[i]+=num[i+1];
    }
    
    
    cout<<ret%mo<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}