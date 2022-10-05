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
ll TO;
int A[100003];
ll T[100003],M[100003];

vector<int> E[100001];

void dfs(int cur,int pre) {
    int i,v=0;
    M[cur]=1;
    T[cur]=A[cur];

    if(cur!=0 && E[cur].size()==1) return;
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        v++;
        dfs(tar,cur);
        T[cur]+=T[tar];
        M[cur] = M[cur]*M[tar]/__gcd(M[cur],M[tar]);
        if(M[cur]>T[cur]) {
            T[cur]=0;
            return;
        }
    }
    
    
    ll mo=1LL<<60;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar==pre) continue;
        T[tar] -= T[tar] % M[cur];
        mo=min(mo,T[tar]);
    }
    T[cur]=v*mo;
    M[cur] *= v;
    
}

void solve() {
    int f,i,j,k,x,y,z,tx,ty;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    FOR(i,N) TO+=A[i];
    
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    
    dfs(0,-1);
    cout << TO-T[0] << endl;
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}