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

int N;
int G[50],GR[50];
int BM[32];
int vis[100002];
map<int,int> gra;

int calc(int v) {
    int mask=0,i,j;
    if(gra.find(v)!=gra.end()) return gra[v];
    
    mask=j=1;
    for(i=2;(1<<i) <= v; i++) if(v & (1<<i)) mask |= 1<<calc(v & BM[i]);
    while(mask & (1<<j)) j++;
    return gra[v]=j;
}

void solve() {
    int f,r,i,j,k,l, x,y;
    ll t;
    
    N=GETi();
    for(i=2;i<32;i++) {
        BM[i]=0x7FFFFFFF;
        for(j=i;j<=31;j+=i) BM[i] ^= 1<<j;
    }
    G[1]=N;
    
    for(i=2;i<=min(100000,N);i++) {
        G[1]--;
        if(vis[i]) continue;
        
        j=1;
        ll t=i;
        while(t*i<=N) t*=i,j++,vis[min(100001LL,t)]++;
        G[j]++;
    }
    
    /*
    // output table
    gra[0]=0;
    calc(0x3FFFFFFE);
    FOR(i,32) _P("%d %d\n",i,gra[(1<<(i+1))-2]);
    */
    GR[1]=1;
    GR[2 ]=2;
    GR[3 ]=1;
    GR[4 ]=4;
    GR[5 ]=3;
    GR[6 ]=2;
    GR[7 ]=1;
    GR[8 ]=5;
    GR[9 ]=6;
    GR[10]= 2;
    GR[11]= 1;
    GR[12]= 8;
    GR[13]= 7;
    GR[14]= 5;
    GR[15]= 9;
    GR[16]= 8;
    GR[17]= 7;
    GR[18]= 3;
    GR[19]= 4;
    GR[20]= 7;
    GR[21]= 4;
    GR[22]= 2;
    GR[23]= 1;
    GR[24]= 10;
    GR[25]= 9;
    GR[26]= 3;
    GR[27]= 6;
    GR[28]= 11;
    GR[29]= 12;

    int nim=0;
    FOR(i,32) if(G[i]%2) nim ^= GR[i];
        
    if(nim==0) _P("Petya\n");
    else _P("Vasya\n");
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}