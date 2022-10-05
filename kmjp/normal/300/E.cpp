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
ll nnp[10000002],A[1000001];

int np;
int prime[1000000];
const int prime_max = 10000003;
static int p[prime_max];
void cprime() {
    int i,j;
    
    np=0;
    ZERO(p);
    for(i=2;i<prime_max;i++) {
        if(p[i]) continue;
        prime[np++]=i;
        for(j=i*2;j<prime_max;j+=i) p[j]=i;
    }
}

int okok(ll M) {
    ll k,t,l;
    
    FOR(k,np) {
        if(nnp[prime[k]]==0) continue;
        t=0;
        l=prime[k];
        while(l<=M) {
            t += M/l;
            l*=prime[k];
        }
        if(t<nnp[prime[k]]) return 0;
    }
    return 1;
}

void solve() {
    int f,r,i,j,k,l, x,y,ma,num,nt;
    int Q,N,K;
    
    cprime();
    
    K=GETi();
    FOR(i,K) A[i]=GETi();
    sort(A,A+K);
    
    j=0;
    for(i=0;j<K;i++) {
        while(A[j]<i && j<K) j++;
        nnp[i]=K-j;
    }
    
    for(j=i;j>=2;j--) {
        if(p[j] && nnp[j]) {
            nnp[p[j]]+=nnp[j];
            nnp[j/p[j]]+=nnp[j];
            nnp[j]=0;
        }
    }
    
    ll L=1;
    ll R=1LL<<60;
    while(R-L>0) {
        ll mid=(R+L)/2;
        
        if(okok(mid)) R=mid;
        else L=mid+1;
    }
    
    cout << L << endl;
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}