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
ll A[30],B[3];
vector<int> BM[2];
ll comb[30][30];

ll mo=1000000007;
ll DP[1<<25];

void solve() {
    int f,r,i,j,k,l,x,y,tx,ty;
    
    N=GETi();
    j=0;
    FOR(i,N) j+=A[i]=GETi();
    K=GETi();
    FOR(i,K) B[i]=GETi();
    //if(K==2 && B[0]==B[1]) K=1;
    //if(K==2 && B[0]>B[1]) swap(B[0],B[1]);
    //if(K==2) B[1]=j-B[1];
    
    DP[0]=1;
    for(i=1;i<1<<N;i++) {
        ll tot=0;
        FOR(j,N) if(i&(1<<j)) {
            tot+=A[j];
            DP[i]+=DP[i^(1<<j)];
        }
        DP[i]%=mo;
        if(K>=1 && tot==B[0]) DP[i]=0;
        if(K>=2 && tot==B[1]) DP[i]=0;
    }
    
    /*
    ll res=1;
    FOR(i,N) res=(res*(i+1))%mo;
    
    FOR(x,N+1) FOR(y,N+1) {
        if(x+y>N) continue;
        ll t=1;
        FOR(i,x) t=(t*(i+1)) % mo;
        FOR(i,y) t=(t*(i+1)) % mo;
        FOR(i,N-x-y) t=(t*(i+1)) % mo;
        comb[x][y]=t;
    }
    
    FOR(i,1<<N) {
        x=0;
        FOR(j,N) if(i & (1<<j)) x+=A[j];
        FOR(j,K) if(x==B[j]) {
            BM[j].push_back(i);
            res = (res + mo - comb[__builtin_popcount(i)][0]) % mo;
        }
    }
    
    if(K==2) {
    }
    */
    
    cout << DP[(1<<N)-1] << endl;
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}