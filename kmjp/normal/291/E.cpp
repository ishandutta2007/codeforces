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
vector<int> E[100001];
string P[100001];
string T;

int KMPT[4*100000];
ll res;

void KMPproc(int c){
    res++;
}

int KMP(string& tar,string& pat, int cur=0) {
    int c,p=0,l,pl;
    
    FOR(c,tar.size()) {
        while(cur>-1 && pat[cur]!=tar[c]) cur=KMPT[cur];
        if(++cur >= pat.size()) {
            KMPproc(c);
            cur=KMPT[cur];
        }
    }
    return cur;
}

void prepKMP(string& str) {
    int i,n;
    
    n=KMPT[0]=-1;
    FOR(i,str.size()) {
        while(n>-1 && str[i]!=str[n]) n=KMPT[n];
        n++;
        KMPT[i+1]=(str[i+1]==str[n])?KMPT[n]:n;
    }
}


ll dfs(int cur, int state) {
    int i;
    
    state = KMP(P[cur], T, state);
    FOR(i,E[cur].size()) dfs(E[cur][i],state);
    
    return res;
    
}

void solve() {
    int f,r,i,j,k,l,x,y;
    int ma=0;
    
    N=GETi();
    FOR(i,N-1) {
        cin >> j >> P[i+2];
        E[j].push_back(i+2);
    }
    cin >> T;
    prepKMP(T);
    res=0;
    dfs(1,0);
    cout << res << endl;
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}