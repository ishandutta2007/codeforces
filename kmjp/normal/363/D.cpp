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

int N,M;
ll A,B[100005],P[100005];

ll okok(int p) {
    int i;
    ll tot=0,tot2=0;;
    if(p>min(N,M)) return -1;
    FOR(i,p) {
        tot2+=P[i];
        if(B[N-p+i]<P[i]) tot+=P[i]-B[N-p+i];
    }
    if(tot>A) return -1;
    return max(tot2-A,0LL);
}

void solve() {
    int f,i,j,k,l,x,y;
    ll r;
    
    cin>>N>>M>>A;
    FOR(i,N) cin>>B[i];
    FOR(i,M) cin>>P[i];
    sort(B,B+N);
    sort(P,P+M);
    
    int lo=0,hi=min(N,M);
    FOR(i,30) {
        int pi=(lo+hi)/2;
        r=okok(pi);
        if(r<0) hi=pi-1;
        else lo=pi;
    }
    lo=min(hi,lo+5);
    while(lo>0 && (r=okok(lo))<0) lo--;
    if(lo==0) _P("%d %d\n",0,0);
    else _P("%d %lld\n",lo,r);
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}