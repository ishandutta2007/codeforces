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

int C[5],N,M,A[1001],B[1001];

void solve() {
    int f,i,j,k,l,r, x,y;
    
    cin>>C[1]>>C[2]>>C[3]>>C[4]>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,M) cin>>B[i];
    
    r=C[4];x=y=0;
    FOR(i,N) x+=A[i]=min(A[i]*C[1],C[2]);
    FOR(i,M) y+=B[i]=min(B[i]*C[1],C[2]);
    r=min(r,x+y);
    r=min(r,C[3]+x);
    r=min(r,C[3]+y);
    r=min(r,C[3]*2);
    
    cout << r << endl;
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}