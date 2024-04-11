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



void solve() {
    int f,r,i,j,k,l;
    ll x,y,rx,ry;
    int N;
    ll A,B;
    string S;
    
    cin>>A>>B;
    cin>>S;
    
    rx=ry=0;
    FOR(i,S.size()) {
        if(S[i]=='U') ry++;
        if(S[i]=='D') ry--;
        if(S[i]=='L') rx--;
        if(S[i]=='R') rx++;
        if(A==rx && B==ry) {
            _P("Yes\n");
            return;
        }
    }
    if(A==0 && B==0) {
        _P("Yes\n");
        return;
    }
    if(rx==0 && ry==0) {
        _P("No\n");
        return;
    }
    
    ll miX,maX,miY,maY;
    if(rx && ry) {
        miX=max(0LL,A/rx-102);
        maX=max(0LL,A/rx+102);
        miY=max(0LL,B/ry-102);
        maY=max(0LL,B/ry+102);
    }
    else if(rx==0) {
        miX=miY=max(0LL,B/ry-102);
        maX=maY=max(0LL,B/ry+102);
    }
    else {
        miY=miX=max(0LL,A/rx-102);
        maY=maX=max(0LL,A/rx+102);
    }
    
    if(miY>maX || miX>maY) {
        _P("No\n");
        return;
    }
    
    x=rx*min(miX,miY);
    y=ry*min(miX,miY);
    FOR(i,max(maX,maY)-min(miX,miY)+2) {
        FOR(j,S.size()) {
            if(S[j]=='U') y++;
            if(S[j]=='D') y--;
            if(S[j]=='L') x--;
            if(S[j]=='R') x++;
            if(A==x && B==y) {
                _P("Yes\n");
                return;
            }
        }
    }
    
    _P("No\n");
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}