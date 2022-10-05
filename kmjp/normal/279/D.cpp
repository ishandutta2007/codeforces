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
int A[100];
vector<pair<int, int> > P[30];
int dp[1<<24];

void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    
    N=GETi();
    FOR(i,N) A[i]=GETi();
    
    if(N==1) {
        _P("1\n");
        return;
    }
    
    FOR(i,N) {
        FOR(j,i) if(A[j]==A[i]) P[i].push_back(make_pair(j,-1));
        FOR(j,i) for(k=j;k<i;k++) {
            if(A[j]+A[k]==A[i]) P[i].push_back(make_pair(j,k));
        }
    }
    
    ZERO(dp);
    dp[1]=1;
    int msb=0;
    for(i=1;i<N;i++) {
        for(k=1<<(i-1);k<(1<<i);k++) {
            if(dp[k]==0) continue;
            FOR(j,P[i].size()) {
                pair<int,int> p = P[i][j];
                
                if((k & (1<<p.first)) == 0) continue;
                if(p.second>= 0 && (k & (1<<p.second)) == 0) continue;
                dp[(k | (1<<i))] = 1;
                FOR(l,i) if(k & (1<<l)) dp[(k | (1<<i)) ^ (1<<l)] = 1;
            }
        }
    }
    
    int mbc=99;
    for(k=1<<(N-1);k<1<<N;k++) {
        if(dp[k]==1) mbc=min(mbc,__builtin_popcount(k));
    }
    
    if(mbc==99) mbc=-1;
    _P("%d\n",mbc);
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}