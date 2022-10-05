#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

ll N,K,M;
ll mo=1000000009;

ll modpow(ll a, ll n, ll p) {
    ll r=1;
    while(n) {
        if(n%2) r=(r*a)%p;
        a=(a*a)%p;
        n>>=1;
    }
    return r;
}

void solve() {
    int f,i,j,k,l, x,y;
    ll ret=0;
    
    cin>>N>>M>>K;
    M=N-M;
    ll t=K*M;
    if(N<=t) return _P("%d\n",N-M);
    N-=t;
    l = (K-1)*M + (N%K);
    N/=K;
    ret = (modpow(2,N+1,mo) - 2) * K + l;
    ret = ((ret%mo)+mo)%mo;
    cout << ret%mo << endl;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}