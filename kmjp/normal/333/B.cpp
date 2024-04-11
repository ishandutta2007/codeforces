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
int NGy[1001],NGx[1001];
int memo[1000];
int okok(int x1,int x2,int y1,int y2) {
    int mask=(3<<6)*x1+(3<<4)*x2+(3<<2)*y1+3*y2;
    int i;
    if(memo[mask]>=0) return memo[mask];
    memo[mask]=0;
    FOR(i,256) {
        if((mask & i) != i) continue;
        if((i&(1<<7)) && (i&(1<<6))) continue;
        if((i&(1<<5)) && (i&(1<<4))) continue;
        if((i&(1<<3)) && (i&(1<<2))) continue;
        if((i&(1<<1)) && (i&(1<<0))) continue;
        if((i&(1<<7)) && (i&(1<<3))) continue;
        if((i&(1<<7)) && (i&(1<<0))) continue;
        if((i&(1<<6)) && (i&(1<<2))) continue;
        if((i&(1<<6)) && (i&(1<<1))) continue;
        if((i&(1<<5)) && (i&(1<<2))) continue;
        if((i&(1<<5)) && (i&(1<<1))) continue;
        if((i&(1<<4)) && (i&(1<<3))) continue;
        if((i&(1<<4)) && (i&(1<<0))) continue;
        memo[mask]=max(memo[mask],__builtin_popcount(i));
    }
    return memo[mask];
}

void solve() {
    int f,i,j,k,l, x,y;
    ll r=0;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        NGx[x-1]=1;
        NGy[y-1]=1;
    }
    MINUS(memo);
    int res=0;
    for(x=1;x<N/2;x++) {
        res += okok(1-NGx[x],1-NGx[N-1-x],1-NGy[x],1-NGy[N-1-x]);
    }
    if(N%2==1) if(NGx[N/2]==0 || NGy[N/2]==0) res++;
    
    cout << res << endl;
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}