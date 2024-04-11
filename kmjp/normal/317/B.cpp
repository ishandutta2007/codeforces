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

int N,T;
int A[2][71][71];
set<int> V[2];

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N>>T;
    A[0][0][0]=N;
    FOR(i,30000) {
        int cur=i%2;
        int tar=1-cur;
        ZERO(A[tar]);
        FOR(x,70) FOR(y,70) {
            if(A[cur][y][x]>=4) {
                if(y>0) A[tar][y-1][x]++;
                if(y-1==0) A[tar][y-1][x]++;
                A[tar][y+1][x]++;
                
                if(x>0) A[tar][y][x-1]++;
                if(x-1==0) A[tar][y][x-1]++;
                A[tar][y][x+1]++;
                A[cur][y][x]-=4;
            }
            A[tar][y][x]+=A[cur][y][x];
        }
        
    }
    
    FOR(i,T) {
        x=abs(GETi());
        y=abs(GETi());
        if(x>70 || y>70) _P("%d\n",0);
        else _P("%d\n",A[0][y][x]);
    }
    
    /*
    
    int aa=0;
    FOR(y,70) {
        FOR(x,70) {
            if(A[0][y][x]==0) _P("  ");
            else _P("%d:",A[0][y][x]);
            //if(A[0][y][x]>=4) {_P("aaaaaaaaaa\n");return;}
            if(x>0 && y>0) aa+=4*A[0][y][x];
            else aa+=A[0][y][x];
        }
        _P("\n");
    }
    _P("%d\n",aa);
    */
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}