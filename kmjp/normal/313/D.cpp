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

ll N,M,K;
ll P[302][302];
ll dp[302][302];

void solve() {
    int f,r,i,j,k,l, x,y,z;
    
    cin>>N>>M>>K;
    
    FOR(x,302) FOR(y,302) P[x][y]=1LL<<50;
    
    FOR(i,M) {
        cin>>x>>y>>f;
        P[x][y]=min(P[x][y],(ll)f);
    }
    
    FOR(i,301) {
        FOR(x,301) for(y=x;y<=300;y++) {
            if(x>0) P[x][y]=min(P[x][y],P[x-1][y]);
            P[x][y]=min(P[x][y],P[x][y+1]);
        }
    }
    
    FOR(x,N+1) {
        FOR(y,N+1) dp[x][y]=1LL<<50;
        dp[x][0]=0;
    }
    
    for(x=1;x<=N;x++) {
        FOR(y,x) dp[x][y]=dp[x-1][y];
        FOR(y,x) for(z=0;z<=x;z++) {
            dp[x][z+(x-y)]=min(dp[x][z+(x-y)], dp[y][z]+P[y+1][x]);
        }
    }
    
    ll res=1LL<<50;
    for(x=K;x<=N;x++) res=min(res,dp[N][x]);
    if(res>=1LL<<50) res=-1;
    cout << res << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}