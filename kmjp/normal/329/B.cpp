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

int W,H;
int sx,sy,ex,ey;
string S[1001];
int dist[1001][1001];

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) {
        if(S[y][x]=='S') {S[y][x]='0'; sx=x;sy=y;}
        if(S[y][x]=='E') {S[y][x]='0'; ex=x;ey=y;}
        dist[y][x]=99999999;
    }
    
    dist[ey][ex]=0;
    queue<int> Q;
    Q.push(ey*10000+ex);
    while(!Q.empty()) {
        int k=Q.front();
        Q.pop();
        int cx=k%10000,cy=k/10000;
        
        FOR(r,4) {
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            int tx=cx+dx[r];
            int ty=cy+dy[r];
            if(tx<0 || tx>=W || ty<0 || ty>=H || S[ty][tx]=='T') continue;
            
            if(dist[ty][tx]>dist[cy][cx]+1) {
                dist[ty][tx]=dist[cy][cx]+1;
                Q.push(ty*10000+tx);
            }
        }
    }
    
    l=0;
    FOR(y,H) FOR(x,W) if(dist[y][x]<=dist[sy][sx] && S[y][x]>'0' && S[y][x]<='9') l+=S[y][x]-'0';
    _P("%d\n",l);
    
    
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}