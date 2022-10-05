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

int L;
char S[5003];
vector<pair<int,int> > G;
int gr[5002],mex[5002];

void solve() {
    int f,r,i,j,k,l, x,y,ma,nt;
    
    gr[1]=gr[2]=1;
    for(i=3;i<=5000;i++) {
        ZERO(mex);
        mex[gr[i-2]]++;
        mex[gr[i-3]]++;
        for(j=2;j<=i-2;j++) mex[gr[j-1]^gr[i-(j+2)]]++;
        for(j=0;mex[j];j++);
        gr[i]=j;
    }
    
    
    GETs(S);
    L=strlen(S);
    
    j=0;
    for(i=1;i<L;i++) { // i=L-1 must fail 
        if(S[i-1]==S[i+1]) j++;
        else {
            if(j) G.push_back(make_pair(i-j,j));
            j=0;
        }
    }
    
    int nim=0;
    ITR(it,G) nim ^= gr[it->second];
    
    if(nim==0) {
        _P("Second\n");
    }
    else {
        _P("First\n");
        ITR(it,G) {
            int tar=nim^gr[it->second];
            //if(tar<gr[it->second]) {
                
                FOR(j,it->second) {
                    if((gr[max(0,j-1)]^gr[max(0,it->second-(j+2))])==tar) {
                        _P("%d\n",it->first+j+1);
                        return;
                    }
                }
            //}
        }
    }
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}