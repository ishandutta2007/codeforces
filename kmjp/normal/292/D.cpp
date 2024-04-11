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

int N,M,K;
int TF[10001][2];

class UF {
    public:
    static const int ufmax=502;
    int ufpar[ufmax],ufrank[ufmax];
    void UF_init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
    int UF_find(int x) {    return (ufpar[x]==x)?(x):(ufpar[x] = UF_find(ufpar[x]));}
    void UF_unite(int x,int y) {
        x = UF_find(x); y = UF_find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y;
        else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

UF uf[2][10002];

void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    
    GET2(&N,&M);
    FOR(i,M) {
        TF[i][0]=GETi()-1;
        TF[i][1]=GETi()-1;
    }
    
    FOR(i,10001) {
        uf[0][i].UF_init();
        uf[1][i].UF_init();
    }
    
    FOR(i,M) {
        uf[0][i+1]=uf[0][i];
        uf[0][i+1].UF_unite(TF[i][0],TF[i][1]);
    }
    for(i=M;i>=1;i--) {
        uf[1][i-1]=uf[1][i];
        uf[1][i-1].UF_unite(TF[i-1][0],TF[i-1][1]);
    }
    
    K=GETi();
    FOR(j,K) {
        int l=GETi()-1;
        int r=GETi()-1;
        
        UF tuf1,tuf2;
        tuf1=uf[0][l];
        tuf2=uf[1][r+1];
        FOR(i,N) tuf1.UF_unite(i,tuf2.UF_find(i));
        
        int n=0;
        FOR(i,N) if(tuf1.UF_find(i)==i) n++;
        _P("%d\n",n);
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}