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

int N,K;
ll X[200001],T[200001];
int M[200001];

void solve() {
    int f,r,i,j,k,l,x,y,tx,ty;
    
    cin >> N >> K;
    FOR(i,N) X[i]=GETi();
    T[0]=X[0];
    for(i=1;i<K;i++) T[i] = T[i-1] + X[i];
    for(i=K;i<N;i++) T[i] = T[i-1] + X[i] - X[i-K];
    
    ll ma=0;
    for(i=2*K-1;i<N;i++) {
        if(i==2*K-1) {
            M[i]=K-1;
        }
        else {
            if(T[i-K] > T[M[i-1]]) M[i]=i-K;
            else M[i]=M[i-1];
        }
        if(T[i]+T[M[i]] > ma) {
            ma=T[i]+T[M[i]];
            x=M[i];
            y=i;
        }
    }
    
    _P("%d %d\n",x-(K-2),y-(K-2));
    
    
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}