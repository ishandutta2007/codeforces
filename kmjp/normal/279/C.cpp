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
int N,M;
int A[100001];
int UP[100001],DO[100001];

void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    
    N=GETi();
    M=GETi();
    FOR(i,N) A[i]=GETi();
    
    i=0;
    FOR(j,N-1) if(A[j]>A[j+1]) while(i<=j) UP[i++]=j;
    while(i<=N-1) UP[i++]=N-1;
    
    i=N-1;
    for(j=N-1;j>=1;j--) if(A[j]>A[j-1]) while(i>=j) DO[i--]=j;
    while(i>=0) DO[i--]=0;
    
    FOR(i,M) {
        x=GETi()-1;
        y=GETi()-1;
        _P("%s\n",(UP[x]>=y || DO[y]<=x || UP[x]==DO[y] || (UP[x]>DO[y] && A[UP[x]]==A[DO[y]]))?"Yes":"No");
    }
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}