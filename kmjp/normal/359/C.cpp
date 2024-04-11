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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

ll mo=1000000007;
int N,X;
ll A[100001],XP[21];

ll modpow(ll a, ll n, ll mo) {
    ll r=1;
    while(n) {
        if(n%2) r=(r*a)%mo;
        a=(a*a)%mo;
        n>>=1;
    }
    return r;
}

void solve() {
    int f,i,j,k,l;
    ll x,y,N;
    
    cin>>N>>X;
    FOR(i,N) cin>>A[i];
    
    XP[0]=1;
    FOR(i,20) {
        if(XP[i]==-1) {
            XP[i+1]=-1;
        }
        else {
            XP[i+1]=XP[i]*X;
            if(XP[i+1]>N) XP[i+1]=-1;
        }
    }
    
    ll s=0;
    FOR(i,N) s+=A[i];
    FOR(i,N) A[i]=s-A[i];
    sort(A,A+N);
    y=A[0];
    FOR(i,N) A[i]-=y;
    x=0;
    FOR(i,N) if(A[i]<=20 && XP[A[i]]>=0) x+=XP[A[i]];
    while(x>0 && (x%X)==0) y++,x/=X;
    y=min(y,s);
    
    _P("%lld\n",modpow(X,y,mo));
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}