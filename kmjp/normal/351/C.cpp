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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
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
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M;
int A[100],B[100];
ll dpdp[41][41][41];
ll dpdp2[2][41];

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,N) cin>>B[i];
    FOR(x,41) FOR(y,41) FOR(i,41) dpdp[x][y][i]=1LL<<40;
    
    FOR(y,2*N+1) {
        dpdp[y][0][y]=0;
        FOR(i,2*N) FOR(x,2*N+1) {
            if(x<2*N) dpdp[y][i+1][x+1]=min(dpdp[y][i+1][x+1],dpdp[y][i][x]+A[i%N]);
            if(x>0) dpdp[y][i+1][x-1]=min(dpdp[y][i+1][x-1],dpdp[y][i][x]+B[i%N]);
        }
    }
    
    ll re =1LL<<40;
    FOR(i,N+1) re = min(re,dpdp[0][N][i]+dpdp[i][N][0]+dpdp[i][2*N][i]*(M/2-1));
    cout << re << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}