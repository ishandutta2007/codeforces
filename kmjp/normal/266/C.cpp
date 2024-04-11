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

int N;
int mat[1001][1001];
int nh[1001],ny[1001];
vector<pair<int, int> > step;

void solve() {
    int f,r,i,j,k,l,x,y;
    
    ZERO(mat);
    N=GETi();
    
    FOR(i,N-1) {
        y=GETi()-1;
        x=GETi()-1;
        mat[x][y]=1;
        ny[y]++;
    }
    
    //tate
    for(y=N-1;y>=0;y--) {
        int nc=0,my=-1;
        int ty;
        FOR(ty,y+1) {
            if(ny[ty]>nc){ nc=ny[ty]; my=ty;}
        }
        if(nc==0) break;
        if(my<y) {
            step.push_back(make_pair(1,my*1000+y));
            swap(ny[my],ny[y]);
            FOR(x,N) swap(mat[x][y],mat[x][my]);
        }
        
    }
    //yoko
    FOR(x,N) nh[x]=N;
    FOR(x,N) for(y=N-1;y>=0;y--) if(mat[x][y]) nh[x]=y;
    
    FOR(x,N) {
        int nc=N+1,mx=-1;
        int tx;
        for(tx=x;tx<N;tx++) {
            if(nh[tx]<nc){ nc=nh[tx]; mx=tx;}
        }
        if(mx==-1) break;
        if(mx!=x) {
            step.push_back(make_pair(2,mx*1000+x));
            swap(nh[mx],nh[x]);
        }
    }
    
    _P("%d\n",step.size());
    FOR(i,step.size()) _P("%d %d %d\n",step[i].first,1+step[i].second/1000,1+(step[i].second%1000));
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}