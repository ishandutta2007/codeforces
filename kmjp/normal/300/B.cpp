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

int N,M;
vector<int> E[50];
vector<int> P[50];
int vis[50];

void dfs(int cur,int ID) {
    int i;
    vis[cur]=ID;
    P[ID].push_back(cur);
    FOR(i,E[cur].size()) if(!vis[E[cur][i]]) dfs(E[cur][i],ID);
}

void solve() {
    int f,r,i,j,k,l,x,y;
    ll t;
    int N,M;
    int tp=0,tm=0;
    
    N=GETi();
    M=GETi();
    
    FOR(i,M) {
        x=GETi()-1;
        y=GETi()-1;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    j=0;
    FOR(i,N) if(!vis[i]) dfs(i,++j);
    
    int NN[4];
    NN[1]=NN[2]=NN[3]=0;
    for(i=1;i<=j;i++) {
        if(P[i].size()>3) {
            _P("-1\n");
            return;
        }
        NN[P[i].size()]++;
    }
    if(NN[2]>NN[1]) {
        _P("-1\n");
        return;
    }
    
    for(i=1;i<=j;i++) {
        if(P[i].size()==3) {
            _P("%d %d %d\n",P[i][0]+1,P[i][1]+1,P[i][2]+1);
            P[i].resize(0);
        }
        if(P[i].size()==1) {
            P[0].push_back(P[i][0]);
            P[i].resize(0);
        }
    }
    
    for(i=1;i<=j;i++) {
        if(P[i].size()==2) {
            _P("%d %d %d\n",P[i][0]+1,P[i][1]+1,P[0][P[0].size()-1]+1);
            P[i].resize(0);
            P[0].resize(P[0].size()-1);
        }
    }
    for(i=0;i<P[0].size();i+=3) _P("%d %d %d\n",P[0][i]+1,P[0][i+1]+1,P[0][i+2]+1);
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}