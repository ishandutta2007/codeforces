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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

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

int H,W,K;
ll val[1001][1001];
ll le[1001][1001];
ll ri[1001][1001];
ll up[1001][1001];
ll sc[1001][1001];

void solve() {
    int f,r,i,j,k,l,cur,tar,ret,loop;
    int x,y,mx,my;
    
    GET3(&H,&W,&K);
    FOR(y,H) FOR(x,W) val[x][y]=GETi();
    FOR(y,H) FOR(x,W) {
        le[x][y]=ri[x][y]=up[x][y]=val[x][y];
        if(y>=1) {
            if(x>=1){
                le[x][y]+=le[x-1][y-1];
                up[x][y]+=le[x-1][y-1];
            }
            if(x<W-1){
                ri[x][y]+=ri[x+1][y-1];
                up[x][y]+=ri[x+1][y-1];
            }
            up[x][y]+=up[x][y-1];
        }
    }
    K--;
    ll ma=-1;
    
    for(y=K;y<H-K;y++) for(x=K;x<W-K;x++) {
        for(i=0;i<=K;i++) {
            ll tsc=up[x][y+i];
            if(y>0) {
                tsc-=up[x+i][y-1]+up[x-i][y-1];
                if(x-i-1>=0) tsc-=le[x-i-1][y-1];
                if(x+i+1<W) tsc-=ri[x+i+1][y-1];
            }
            if(y>i) tsc+=up[x][y-i-1];
            
            sc[x][y]+=tsc;
        }
        if(sc[x][y]>ma) {
            ma=sc[x][y];
            mx=x;my=y;
        }
    }
    
    _P("%d %d\n",my+1,mx+1);
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}