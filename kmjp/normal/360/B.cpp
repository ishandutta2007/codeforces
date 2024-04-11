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

int N,K;
ll A[10000];
int dpdp[2005];

int okok(ll piv) {
    int x,y;
    
    MINUS(dpdp);
    FOR(x,K+1) dpdp[K-x]=x;
    
    FOR(x,N) for(y=x+1;y<N;y++) {
        if(abs(A[y]-A[x])<=piv*(y-x)) dpdp[y]=max(dpdp[y],dpdp[x]-(y-x-1));
    }
    FOR(x,N) if(dpdp[x]>=(N-x-1)) return 1;
    
    
    return 0;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K;
    FOR(i,N) cin>>A[i];
    
    if(K>=N-1) return _P("0\n");
    
    ll lo=0,hi=1LL<<35;
    FOR(i,40) {
        ll mi=(lo+hi)/2;
        if(okok(mi)) hi=mi;
        else lo=mi;
    }
    lo=max(lo-10,0LL);
    while(!okok(lo)) lo++;
    cout << lo << endl;
    
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}