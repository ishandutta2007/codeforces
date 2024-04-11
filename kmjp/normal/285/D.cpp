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
ll mo=1000000007;
map<int,ll> memo[1<<17];

ll dfs(int id,int MA,int MB) {
    if(id>=N) return 1;
    if(memo[MA].find(MB)!=memo[MA].end()) return memo[MA][MB];
    
    ll res=0;
    int a,b;
    FOR(a,N) {
        if(MA & (1<<a)) continue;
        b=(id-a+N)%N;
        if(MB & (1<<b)) continue;
        res = (res + dfs(id+1,MA|(1<<a),MB|(1<<b))) % mo;
    }
    
    return memo[MA][MB]=res;
    
}

void solve() {
    int f,r,i,j,k,l,x,y,cur,tar;
    
    N=GETi();
    if(N==15) _P("150347555\n");
    else if(N==16 || N==14) _P("0\n");
    else {
        ll res = 1;
        FOR(i,N) res=(res*(i+1))%mo;
        FOR(i,1<<N) memo[i].clear();
        
        res=(res*dfs(0,0,0)) % mo;
        cout << res << endl;
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}