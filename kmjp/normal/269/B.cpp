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

typedef signed long long s64;
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

int N,M;
int T[5001];
double X[5001];
int L[5003][5003];
int NU[5003][5003];

int calc(int cur, int fin) {
    int i,j;
    if(cur>=N) return 0;
    if(L[cur][fin]!=-1) return L[cur][fin];
    
    if(fin>=T[cur]) {
        L[cur][fin]=calc(cur+1,fin);
    }
    else {
        j=0;
        //for(i=cur+1;i<N;i++) if(T[i]>=fin && T[i]<T[cur]) j++;
        j=NU[cur][fin];
        if(j>0) L[cur][fin]=min(j+calc(cur+1,T[cur]),1+calc(cur+1,fin));
        else L[cur][fin]=min(j+calc(cur+1,T[cur]),calc(cur+1,fin));
    }
    return L[cur][fin];
}

void solve() {
    int f,r,i,j,k,l;
    
    
    GET2(&N,&M);
    FOR(i,N) {
        T[i]=GETi();
        scanf("%lf",&X[i]);
    }
    
    MINUS(L);
    
    FOR(i,N) for(j=i+1;j<N;j++) {
        if(T[i]>T[j]) NU[i][T[j]]++;
    }
    
    FOR(i,N) {
        for(j=T[i]-1;j>=0;j--) NU[i][j]+=NU[i][j+1];
    }
    
    
    
    
    int res=calc(0,0);
    
    _P("%d\n",res);
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}