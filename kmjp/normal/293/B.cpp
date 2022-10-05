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

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
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

int H,W,K,unfixed;
int A[1001][1001];
int UM[11][11];
int V[11][11];

ll P[11][11];
ll mo=1000000007;

int count(int nk){
    int as[11];
    int y,x,nf;
    ZERO(as);
    FOR(y,H) FOR(x,W) if(A[y][x]!=0) {
        if(as[V[y][x]]!=0 && as[V[y][x]]!=A[y][x]) return 0;
        as[V[y][x]]=A[y][x];
    }
    FOR(x,nk) for(y=x+1;y<nk;y++) if(as[x+1] && as[y+1] && as[x+1]==as[y+1]) return 0;
    nf=0;
    FOR(x,nk) if(as[x+1]) nf++;
    return P[K-nf][nk-nf];
}

ll dfs(int x,int y,int nk) {
    int i;
    ll sum=0;
    
    UM[y][x]=0;
    if(y>0) UM[y][x]|=UM[y-1][x];
    if(x>0) UM[y][x]|=UM[y][x-1];
    
    int ny,nx;
    nx=x+1;
    ny=y-1;
    if(ny<0 || nx>=W) {
        nx=0;
        ny=x+y+1;
    }
    while(ny>=H) ny--,nx++;
    
    for(i=1;i<=min(K,nk+1);i++) {
        if(UM[y][x]&(1<<i)) continue;
        if(W+H-1==K && i!=x+y+1) continue;
        
        UM[y][x] |= 1<<i;
        V[y][x]=i;
        
        if(x==W-1 && y==H-1) sum+=count(nk+(i==(nk+1)));
        else sum+=dfs(nx,ny,nk+(i==(nk+1)));
        sum%=mo;
        
        UM[y][x] ^= 1<<i;
    }
    return sum;
    
}

void solve() {
    int f,r,i,j,k,l,x,y,tx,ty;
    
    H=GETi();
    W=GETi();
    K=GETi();
    FOR(y,H) FOR(x,W) A[y][x]=GETi();
    
    if(H+W-1>K) {
        _P("0\n");
        return;
    }
    
    for(x=0;x<=10;x++) {
        P[x][0]=1;
        FOR(y,x) P[x][y+1]=(P[x][y]*(x-y))%mo;
    }
    
    ZERO(UM);
    cout << dfs(0,0,0) << endl;
    
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}