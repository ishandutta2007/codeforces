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
int N,D;
ll X[101],Y[101];
ll A[102];
ll Di[101][101];

int test(ll v){
    int i,y;
    ll EN[101];
    
    FOR(i,N) EN[i]=-1;
    EN[0]=v;
    
    int vis[102];
    ZERO(vis);
    queue<int> q;
    
    q.push(0);
    
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        vis[x]=0;
        
        for(y=1;y<N;y++) if(x!=y && EN[x]-D*Di[x][y]>=0) {
            if(EN[y]<EN[x]-D*Di[x][y]+A[y]) {
                EN[y]=EN[x]-D*Di[x][y]+A[y];
                if(vis[y]==0) {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
        if(EN[N-1]>=0) return 1;
    }
    return 0;
    
}

void solve() {
    int f,r,i,j,k,l,x,y;
    
    N=GETi();
    D=GETi();
    int c=0,ma=0;
    FOR(i,N-2) A[i+1]=GETi();
    FOR(i,N) {
        X[i]=GETi();
        Y[i]=GETi();
    }
    FOR(x,N) FOR(y,N) Di[x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
    
    ll L=0,R=1LL<<30;
    FOR(i,32) {
        int P=(L+R)/2;
        if(test(P)) R=P;
        else L=P;
    }
    
    L=max(0LL,L-2);
    while(1) {
        if(test(L)) {
            _P("%lld\n",L);
            return;
        }
        L++;
    }
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}