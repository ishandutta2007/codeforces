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

int N,A[3][10000];
int dpdp[2][3001];

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N) cin>>A[0][i];
    FOR(i,N) cin>>A[1][i];
    FOR(i,N) cin>>A[2][i];
    
    dpdp[0][N]=A[0][N-1];
    dpdp[1][N]=A[1][N-1];
    for(i=N-1;i>=1;i--) {
        dpdp[0][i]=max(A[0][i-1]+dpdp[1][i+1],A[1][i-1]+dpdp[0][i+1]);
        dpdp[1][i]=max(A[1][i-1]+dpdp[1][i+1],A[2][i-1]+dpdp[0][i+1]);
    }
    
    _P("%d\n",dpdp[0][1]);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}