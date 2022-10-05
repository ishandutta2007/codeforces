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
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)
#define _CO(x) { cout << x << endl;}
#define _CI(x) { cin >> x;}

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
vector<pair<int,int> > E[5002];
vector<ll> D[5002];
vector<int> Vs;
int CV[5002];
int CVP[5002];


void dfs(int cur, int pre, int dist) {
    int i;
    
    FOR(i,Vs.size()) D[max(cur,Vs[i])][min(cur,Vs[i])] = D[max(pre,Vs[i])][min(pre,Vs[i])] + dist;
    Vs.push_back(cur);
    
    FOR(i,E[cur].size()) {
        if(E[cur][i].first==pre) continue;
        dfs(E[cur][i].first,cur,E[cur][i].second);
    }
}

int numchild(int cur,int pre) {
    int i;
    if(CVP[cur]==pre) return CV[cur];
    CVP[cur]=pre;
    CV[cur]=1;
    FOR(i,E[cur].size()) {
        if(E[cur][i].first==pre) continue;
        CV[cur]+=numchild(E[cur][i].first, cur);
    }
    return CV[cur];
}

ll localtotal(int cur,int pre, ll tcnum) {
    int i;
    ll tt=0;
    
    FOR(i,E[cur].size()) {
        if(E[cur][i].first==pre) continue;
        tt += localtotal(E[cur][i].first, cur, tcnum) + 
            (ll)E[cur][i].second*(tcnum-CV[E[cur][i].first])*(ll)CV[E[cur][i].first];
    }
    return tt;
}

ll getmin(int cur,int pre, ll curt,ll tcnum) {
    ll mint=curt;
    int i;
    FOR(i,E[cur].size()) {
        if(E[cur][i].first==pre) continue;
        mint = min(mint, getmin(E[cur][i].first, cur, curt + E[cur][i].second*(tcnum-2*CV[E[cur][i].first]),tcnum));
    }
    return mint;
    
}

ll minroad(int X,int Y,ll C) {
    int i;
    ll txc=0,tyc=0,tt;
    
    numchild(X,Y);
    numchild(Y,X);
    tt = localtotal(X,Y,CV[X]) + localtotal(Y,X,CV[Y]);
    
    FOR(i,N) {
        if(D[max(i,X)][min(i,X)]<D[max(i,Y)][min(i,Y)]) txc += D[max(i,X)][min(i,X)];
        else tyc += D[max(i,Y)][min(i,Y)];
    }
    txc = getmin(X,Y,txc,CV[X]);
    tyc = getmin(Y,X,tyc,CV[Y]);
    
    /*
    _P("::%d %d : %lld %lld : %lld %lld :",X,Y,localtotal(X,Y,CV[X]),localtotal(Y,X,CV[Y]),txc,tyc);
    FOR(i,N) _P("%d ",CV[i]);
    _P("\n");
    */
    
    return tt + txc*CV[Y]+tyc*CV[X]+C*CV[X]*(ll)CV[Y];
}

void solve() {
    int f,r,i,j,k,l,x,y,cur,tar;
    
    N=GETi();
    FOR(i,5000) D[i].resize(i+2,0);
    FOR(i,5000) CVP[i]=-2;
    Vs.reserve(5001);
    FOR(i,N-1) {
        x=GETi()-1;
        y=GETi()-1;
        r=GETi();
        E[x].push_back(make_pair(y,r));
        E[y].push_back(make_pair(x,r));
    }
    
    dfs(0,-1,0);
    
    ll mc=1LL<<60;
    FOR(x,N) FOR(y,E[x].size()) if(x<E[x][y].first) mc=min(mc, minroad(x,E[x][y].first,E[x][y].second));
    cout << mc << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}