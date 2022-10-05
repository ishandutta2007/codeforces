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
int W[1000];
int NP[2];

ll MP[202][52][52];
ll MO=1000000007;
ll C[60][60];
void solve() {
    int f,r,i,j,k,l,x,y,mp,loop,px,py;
    ll t;
    
    ZERO(C);
    C[0][0]=1;
    for(x=1;x<60;x++){
        C[x][0]=C[x][x]=1;
        for(y=1;y<x;y++) C[x][y]=(C[x-1][y-1]+C[x-1][y])%MO;
    }
    
    N=GETi();
    K=GETi()/50;
    FOR(i,N) {
        W[i]=GETi()/50;
        NP[W[i]-1]++;
    }
    
    
    
    
    ZERO(MP);
    MP[0][NP[0]][NP[1]]=1;
    
    FOR(loop,202) {
        MP[loop+1][NP[0]][NP[1]]=MO;
        FOR(x,NP[0]+1) FOR(y,NP[1]+1) {
            if(MP[loop][x][y]==0) continue;
            FOR(px,x+1) FOR(py,y+1) {
                if(px+py==0) continue;
                if(px+py*2<=K) MP[loop+1][NP[0]-x+px][NP[1]-y+py] = 
                    (MP[loop+1][NP[0]-x+px][NP[1]-y+py]+MP[loop][x][y]*((C[x][px]*C[y][py])%MO)) % MO;
            }
        }
        
        if(loop%2==0 && MP[loop+1][NP[0]][NP[1]]!=MO) {
            _P("%d\n%d\n",loop+1,(int)MP[loop+1][NP[0]][NP[1]]);
            return;
        }
    }
    
    _P("-1\n0\n");
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}