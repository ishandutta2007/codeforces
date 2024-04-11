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

int H,W;
string S[501];
vector<pair<char,int> > V;
int stat[501][501];

void dfs(int cx,int cy,int first) {
    int i;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    S[cy][cx]='#';
    FOR(i,4) {
        int tx=cx+dx[i];
        int ty=cy+dy[i];
        if(tx<0 || tx>=W || ty<0 || ty>=H || S[ty][tx]!='B') continue;
        dfs(tx,ty,0);
    }
    if(first==0) {
        V.push_back(make_pair('D',cy*1000+cx));
        V.push_back(make_pair('R',cy*1000+cx));
    }
}

void solve() {
    int f,r,i,j,k,l,x,y,tx,ty;
    
    cin >> H >> W;
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) if(S[y][x]!='#') {
        V.push_back(make_pair('B',y*1000+x));
        S[y][x]='B';
    }
    
    FOR(y,H) FOR(x,W) if(S[y][x]=='B') dfs(x,y,1);
    
    _P("%d\n",V.size());
    FOR(i,V.size()) _P("%c %d %d\n",V[i].first,1+V[i].second/1000,1+V[i].second%1000);
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}