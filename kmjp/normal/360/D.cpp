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


int N,M,P;
ll A[100001];
map<ll,int> ndiv;
ll ret;

set<ll> enumdiv(ll n) {
    set<ll> S;
    for(ll i=1;i*i<=n;i++) if(n%i==0) S.insert(i),S.insert(n/i); 
    return S;
}
ll modpow(ll a, ll n, ll mo) {
    ll r=1;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>P;
    FOR(i,N) cin>>A[i];
    y=P-1;
    FOR(i,M) cin>>x, y=__gcd(y,x+(P-1));
    set<ll> div=enumdiv(P-1);
    
    FOR(i,N) {
        ITR(it,div) if(modpow(A[i],y*(*it),P)==1) {
            ndiv[(P-1)/(*it)]=0;
            break;
        }
    }
    for(map<ll,int>::reverse_iterator rit=ndiv.rbegin();rit!=ndiv.rend();rit++) {
        rit->second=(P-1)/rit->first;
        ITR(it,ndiv) if(it->first>rit->first && it->first%rit->first==0) rit->second-=it->second;
        ret+=rit->second;
    }
    
    
    cout<<ret<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}