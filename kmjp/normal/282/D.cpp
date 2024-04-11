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

int N;
int A[5];
int memo[301][301];
int memo2[301][301][301];

int win2(int A,int B) {
    if(memo[A][B]>=0) return memo[A][B];
    if(A==0 && B==0) return memo[A][B]=0;
    if(A==0 || B==0) return memo[A][B]=1;
    
    int i;
    for(i=min(A,B);i>0;i--) if(win2(A-i,B-i)==0) return memo[A][B]=1;
    for(i=A;i>0;i--) if(win2(A-i,B)==0) return memo[A][B]=1;
    for(i=B;i>0;i--) if(win2(A,B-i)==0) return memo[A][B]=1;
    return memo[A][B]=0;
}

int win3(int A,int B,int C) {
    //if(A>B) swap(A,B);
    //if(B>C) swap(B,C);
    //if(A>B) swap(A,B);
    
    if(memo2[A][B][C]>=0) return memo2[A][B][C];
    //if(C==0) return memo2[A][B][C]=0;
    //if(B==0) return memo2[A][B][C]=1;
    
    int i;
    for(i=C;i>0;i--) if(win3(A-i,B-i,C-i)==0) return memo2[A][B][C]=1;
    return memo2[A][B][C]=((A^B^C)!=0);
}

void solve() {
    int i,j,k,x,y;
    
    N=GETi();
    FOR(i,N) A[i]=GETi();
    sort(A,A+N);
    reverse(A,A+N);
    MINUS(memo);
    MINUS(memo2);
    
    if(N==1) _P(A[0]?"BitLGM\n":"BitAryo\n");
    else if(N==2) _P(win2(A[0],A[1])?"BitLGM\n":"BitAryo\n");
    else _P(win3(A[0],A[1],A[2])?"BitLGM\n":"BitAryo\n");
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}