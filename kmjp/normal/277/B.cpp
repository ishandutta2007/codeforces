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
int M,N;

void solve() {
    int f,r,i,j,k,l,x,y;
    
    N=GETi();
    M=GETi();
    
    if(M==3 && N==4) {
        _P("0 0\n");
        _P("5 0\n");
        _P("-5 -5\n");
        _P("-5 5\n");
        return;
    }
    if(M==3 && N>=5) {
        _P("-1\n");
        return;
    }
    
    if(M==4 && N>=7) {
        FOR(i,M) {
            x = 10000*cos(1+2*3.1415926535*i/M);
            y = 10000*sin(1+2*3.1415926535*i/M);
            _P("%d %d\n",x,y);
            if(M+i<N) {
                x = 1000000*cos(1+2*3.1415926535*i/(N-M));
                y = 1000000*sin(1+2*3.1415926535*i/(N-M));
                _P("%d %d\n",x,y);
            }
        }
    }
    else if(M%2) {
        FOR(i,M) {
            x = 10000*cos(2*3.1415926535*i/M);
            y = 10000*sin(2*3.1415926535*i/M);
            _P("%d %d\n",x,y);
            if(M+i<N) {
                x = 1000000*cos(2*3.1415926535*i/M);
                y = 1000000*sin(2*3.1415926535*i/M);
                _P("%d %d\n",x,y);
            }
        }
    }
    else {
        FOR(i,M) {
            x = 10000*cos(1+2*3.1415926535*i/(M+1));
            y = 10000*sin(1+2*3.1415926535*i/(M+1));
            _P("%d %d\n",x,y);
            if(M+i<N) {
                x = 1000000*cos(2*3.1415926535*(1+i)/(M+1));
                y = 1000000*sin(2*3.1415926535*(1+i)/(M+1));
                _P("%d %d\n",x,y);
            }
        }
    }
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}