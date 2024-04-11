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
int H,W;
char mat[60][60];

int okok() {
    int y,x,y2,x2,tx,ty,l;
    int vis[60][60];
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    FOR(y,H) FOR(x,W) {
        if(mat[y][x]=='W') continue;
        
        MINUS(vis);
        vis[y][x]=0;
        
        FOR(l,4) {
            tx=x;ty=y;
            while(1) {
                tx+=dx[l];
                ty+=dy[l];
                if(tx<0 || tx>=W || ty<0 || ty>=H) break;
                if(mat[ty][tx]=='W') break;
                vis[ty][tx]=1;
            }
        }
        FOR(y2,H) FOR(x2,W) {
            if(vis[y2][x2] != 1) continue;
            FOR(l,4) {
                tx=x2;ty=y2;
                while(1) {
                    tx+=dx[l];
                    ty+=dy[l];
                    if(tx<0 || tx>=W || ty<0 || ty>=H) break;
                    if(mat[ty][tx]=='W') break;
                    if(vis[ty][tx]==-1) vis[ty][tx]=2;
                }
            }
        }
        FOR(y2,H) FOR(x2,W) {
            if(mat[y2][x2]=='B' && vis[y2][x2]==-1) return 0;
        }
    }
    
    return 1;
}

void solve() {
    int f,r,i,j,k,l,x,y;
    
    GET2(&H,&W);
    FOR(y,H) GETs(mat[y]);
    
    _P("%s\n",(okok()?"YES":"NO"));
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}