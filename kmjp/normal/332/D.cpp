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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
int GETi() { int i;scanf("%d",&i); return i;}

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,K;
int M[2010][2010];
double C[2010][2010];

void solve() {
    int r,i,j,k,l,x,y,tx,ty;
    
    cin>>N>>K;
    FOR(x,N-1) FOR(y,N-1-x) M[x][x+1+y]=M[x+1+y][x]=GETi();
    
    FOR(i,2001) C[i][0]=C[i][i]=1;
    for(i=1;i<2001;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j]);
    double R=0;
    FOR(x,N) {
        double T=0;
        j=0;
        FOR(y,N) if(x!=y && M[x][y]!=-1) j++,T+=M[x][y];
        if(j>=K) R+=T*C[j-1][K-1];
    }
    R/=C[N][K];
    cout << (ll)R << endl;
    
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}