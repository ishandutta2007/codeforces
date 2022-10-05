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

int K;
int A[101],ZA[101];;
vector<int> Z;
int NZ;

int zeromask(int i) {
    int res=0;
    if(i==0) res |= 1;
    if(i%10) res |= 2;
    if((i/10)%10) res |= 4;
    if(i==100) res |= 8;
    return res;
}

void solve() {
    int f,r,i,j,k,l, x,y,ma,num,nt;
    ll tot = 0;
    
    NZ=-1;
    cin>>K;
    FOR(i,K) A[i]=GETi();
    FOR(i,K) ZA[i]=zeromask(A[i]);
    
    k=0;
    FOR(i,K) {
        if(((k & ZA[i]) == 0) && __builtin_popcount(ZA[i])==1) {
            Z.push_back(A[i]);
            k|=ZA[i];
        }
    }
    FOR(i,K) {
        if((k & ZA[i]) == 0) {
            Z.push_back(A[i]);
            k|=ZA[i];
        }
    }
    
    _P("%d\n",Z.size());
    FOR(i,Z.size()) _P("%d ",Z[i]);
    _P("\n");
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}