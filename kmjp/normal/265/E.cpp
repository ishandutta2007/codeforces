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

int N,Q;
int V[100001],C[100001];
ll MA;
ll CM[100001];
ll A,B;
int MC1,MC2;
void solve() {
    int f,r,i,j,k,l,cur,tar,ret,loop;
    int res,x,y;
    ll c;
    
    GET2(&N,&Q);
    FOR(i,N) V[i]=GETi();
    FOR(i,N) C[i]=GETi();
    
    FOR(i,Q) {
        A=GETi();
        B=GETi();
        fill(CM, CM+100001, -(1LL<<60));
        CM[0]=0;
        MA=MC1=MC2=0;
        FOR(x,N) {
            
            if(MC1==C[x]) c = max(CM[MC1] + V[x]*A, CM[MC2] + V[x]*B);
            else c = max(CM[MC1] + V[x]*B, CM[C[x]] + V[x]*A);
            
            if(c > CM[C[x]]) {
                CM[C[x]] = c;
                if(MC1!=C[x] && MC2!=C[x]) {
                    if(c>=CM[MC1]) {
                        MC2=MC1;
                        MC1=C[x];
                    }
                    else if(c>=CM[MC2]) {
                        MC2=C[x];
                    }
                }
                else if(MC2==C[x]) {
                    if(CM[MC2]>CM[MC1]) swap(MC1,MC2);
                }
            }
            MA=max(MA, c);
        }
        _P("%lld\n",MA);
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}