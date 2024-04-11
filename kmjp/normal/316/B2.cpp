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

int N,X;
int A[1001],B[1001],vis[1001],bit[1001];

void solve() {
    int f,r,i,j,k,l, x,y;
    int q=0;
    
    cin>>N>>X;
    FOR(i,N) {
        cin>>A[i+1];
        B[A[i+1]]=i+1;
    }
    
    x=1;y=X;
    vis[y]++;
    while(A[y]!=0) {
        x++;
        y=A[y];
        vis[y]++;
    }
    
    bit[x]=1;
    FOR(i,N) {
        if(A[i+1]!=0 || vis[i+1]) continue;
        x=1;y=i+1;
        while(B[y]!=0) x++,y=B[y];
        for(y=N-x;y>=0;y--) if(bit[y]) bit[y+x]++;
    }
    
    FOR(i,N+1) if(bit[i]) _P("%d\n",i);
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}