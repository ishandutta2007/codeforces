#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,X,P;

bool isprime(ll v) {
    for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
    return true;
}

ll modpow(ll a, ll n, ll mo) {
    ll r=1;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}

bool is_prim_root_modulo(ll b,ll p) {
    ll cur=1,i;
    if(!isprime(p)) return false;
    for(i=2;i*i<=p-1;i++) if((p-1)%i==0) {
        if(modpow(b,i,p)==1) return false;
        if(modpow(b,(p-1)/i,p)==1) return false;
    }
    return true;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>X;
    P=N+1;
    if(isprime(P)){ for(ll B=X-1; B>=2;B--) if(B%P && is_prim_root_modulo(B,P)) return _P("%lld\n",B);}
    _P("-1\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}