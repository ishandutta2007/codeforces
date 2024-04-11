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
ll co[501][501];
ll res[501];
vector<int> V;
int fin[501];

void solve() {
    int f,r,i,j,k,l,x,y;
    ll t;
    
    N=GETi();
    FOR(x,N) FOR(y,N) co[x][y]=GETi();
    FOR(x,N) V.push_back(GETi()-1);
    reverse(V.begin(),V.end());
    
    ll su=0;
    FOR(i,N) {
        FOR(x,i+1) FOR(y,i+1) co[V[x]][V[i]] = min(co[V[x]][V[i]], co[V[x]][V[y]]+co[V[y]][V[i]]);
        FOR(x,i+1) FOR(y,i+1) co[V[i]][V[x]] = min(co[V[i]][V[x]], co[V[i]][V[y]]+co[V[y]][V[x]]);
        FOR(x,i+1) FOR(y,i+1) co[V[x]][V[y]] = min(co[V[x]][V[y]], co[V[x]][V[i]]+co[V[i]][V[y]]);
        
        FOR(x,i+1) FOR(y,i+1) res[N-1-i]+=co[V[x]][V[y]];
    }
    
    FOR(i,N) {
        if(i!=0) cout << " ";
        cout << res[i];
    }
    
    cout << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}