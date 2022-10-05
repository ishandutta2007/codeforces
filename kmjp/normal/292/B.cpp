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

int N,M;
vector<int> E[100001];

int star() {
    int i,ng=0;
    int e=0,m=0;
    
    FOR(i,N) {
        if(E[i].size()==1) e++;
        if(E[i].size()==M) m++;
    }
    return (e==N-1 && m==1);
}
int vis[1000001];
int ring() {
    int i,s=0,pre;
    
    ZERO(vis);
    FOR(i,N) {
        int c=s;
        vis[s]=1;
        if(i==0) s=E[s][0];
        else s=E[s][0]+E[s][1]-pre;
        if(i!=N-1 && vis[s]) return 0;
        pre=c;
    }
    
    return s==0;
}

int bus() {
    int s=-1,e=-1;
    int i,n;
    
    FOR(i,N) {
        if(E[i].size()==1) {
            if(s>=0 && e>=0) return 0;
            if(s==-1) s=i;
            else e=i;
        }
        else if(E[i].size()!=2) return 0;
    }
    if(e==-1) return 0;
    
    int pre;
    FOR(i,N-1) {
        int c=s;
        if(i==0) s=E[s][0];
        else s=E[s][0]+E[s][1]-pre;
        pre=c;
    }
    
    return s==e;
}

void solve() {
    int f,r,i,j,k,l,x,y;
    
    N=GETi();
    M=GETi();
    
    if(N!=M && N!=M+1) {
        _P("unknown topology\n");
        return;
    }
    
    FOR(i,M) {
        x=GETi()-1;
        y=GETi()-1;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    if(N==M) {
        if(ring()) {
            _P("ring topology\n");
            return;
        }
    }
    else {
        if(bus()) {
            _P("bus topology\n");
            return;
        }
        if(star()) {
            _P("star topology\n");
            return;
        }
    }
    
    _P("unknown topology\n");
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}