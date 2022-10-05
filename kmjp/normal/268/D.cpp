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

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,H;
ll DP[2][2][32][32][32];
ll MO=1000000009;


void solve() {
    int x,y,i,j,res,TM,nc,th[4];
    ll o,p;
    
    GET2(&N,&H);
    DP[0][1][H][H][H]=1;

    for(y=1;y<=N;y++) {
        int cur=(y-1)%2;
        int tar=y%2;
        ZERO(DP[tar]);
        
        FOR(th[0],H+1) for(th[1]=th[0];th[1]<=H;th[1]++) for(th[2]=th[1];th[2]<=H;th[2]++) {
            FOR(x,2) {
                ll& cv=DP[cur][x][th[0]][th[1]][th[2]];
                if(cv==0) continue;
                //same
                ll& dps=DP[tar][x][max(th[0]-1,0)][max(th[1]-1,0)][max(th[2]-1,0)];
                dps=(dps + cv)%MO;
                
                if(x==0) {
                    ll& dp1=DP[tar][th[0]>0][0][max(th[1]-1,0)][max(th[2]-1,0)];
                    dp1=(dp1 + cv)%MO;
                    
                    ll& dp2=DP[tar][th[1]>0][0][max(th[0]-1,0)][max(th[2]-1,0)];
                    dp2=(dp2 + cv)%MO;
                    
                    ll& dp3=DP[tar][th[2]>0][0][max(th[0]-1,0)][max(th[1]-1,0)];
                    dp3=(dp3 + cv)%MO;
                }
                else {
                    ll& dp1=DP[tar][th[0]>0][max(th[1]-1,0)][max(th[2]-1,0)][H-1];
                    dp1=(dp1 + cv)%MO;
                    
                    ll& dp2=DP[tar][th[1]>0][max(th[0]-1,0)][max(th[2]-1,0)][H-1];
                    dp2=(dp2 + cv)%MO;
                    
                    ll& dp3=DP[tar][th[2]>0][max(th[0]-1,0)][max(th[1]-1,0)][H-1];
                    dp3=(dp3 + cv)%MO;
                }
            }
            
        }
    }
    
    o=0;
    i=N%2;
    FOR(x,2) {
        FOR(th[0],H+1) for(th[1]=th[0];th[1]<=H;th[1]++) for(th[2]=th[1];th[2]<=H;th[2]++) {
            if(x || th[2]) {
                o+=DP[i][x][th[0]][th[1]][th[2]];
                o %= MO;
            }
        }
    }
    _P("%lld\n",o);
    
    return;
}

int main(int argc,char** argv){
    struct timeval start,end,ts;
    if(argc>1) freopen(argv[1], "r", stdin);
    gettimeofday(&start,NULL);  solve();    gettimeofday(&end,NULL);
    ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    //_E("**Total time: %lld ms\n",span/1000);
    return 0;
}