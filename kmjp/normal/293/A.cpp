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

int N;
char A[2000020];
char B[2000020];
int NN[2][2];


void solve() {
    int r,i,j,k,l,x,y;
    
    N=GETi();
    GETs(A);
    GETs(B);
    
    ZERO(NN);
    FOR(i,2*N) NN[A[i]-'0'][B[i]-'0']++;
    FOR(i,N) {
        // A
        int AP=0;
        if(NN[1][1]) { NN[1][1]--; AP=1;}
        else if(NN[1][0]) { NN[1][0]--; AP=1;}
        else if(NN[0][1]) { NN[0][1]--;}
        else NN[0][0]--;
        
        int BP=0;
        if(NN[1][1]) { NN[1][1]--; BP=1;}
        else if(NN[0][1]) { NN[0][1]--; BP=1;}
        else if(NN[1][0]) { NN[1][0]--;}
        else NN[0][0]--;
        
        if(AP>BP) {
            _P("First\n");
            return;
        }
        if(AP<BP) {
            _P("Second\n");
            return;
        }
    }
    _P("Draw\n");
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}