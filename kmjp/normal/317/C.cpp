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

int N,V,E;
int mat[301][301];
int A[301],B[301];
vector<pair<pair<int,int>,int> > R;

void flow2(vector<int>& P,int si,int ti,int d) {
    int i;
    if(si==ti) return;
    if(A[P[si+1]]+d <= V) {
        A[P[si]]-=d;
        A[P[si+1]]+=d;
        R.push_back(make_pair(make_pair(P[si],P[si+1]),d));
        flow2(P,si+1,ti,d);
    }
    else {
        int d2 = V-A[P[si+1]];
        A[P[si]]-=d2;
        A[P[si+1]]+=d2;
        if(d2>0) R.push_back(make_pair(make_pair(P[si],P[si+1]),d2));
        flow2(P,si+1,ti,d);
        A[P[si]]-=d-d2;
        A[P[si+1]]+=d-d2;
        R.push_back(make_pair(make_pair(P[si],P[si+1]),d-d2));
    }
}

int flow(int s,int t,int d) {
    int i,j,y;
    vector<int> P;
    P.push_back(s);
    for(i=s;i!=t;) {
        FOR(y,N) if(mat[i][y]==1 && mat[y][t]==mat[i][t]-1) break;
        P.push_back(i=y);
    }
    
    flow2(P,0,P.size()-1,d);
}

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N>>V>>E;
    FOR(i,N) cin>>A[i];
    FOR(i,N) cin>>B[i];
    
    FOR(x,N) FOR(y,N) mat[x][y]=9999;
    FOR(x,N) mat[x][x]=0;
    FOR(i,E) {
        cin>>x>>y;
        mat[x-1][y-1]=mat[y-1][x-1]=1;
    }
    FOR(i,N) FOR(j,N) FOR(k,N) mat[j][k] = min(mat[j][k], mat[j][i]+mat[i][k]);
    FOR(x,N) FOR(y,N) {
        if(mat[x][y]>N) continue;
        j = min(A[x]-B[x],B[y]-A[y]);
        if(j<=0) continue;
        flow(x,y,j);
    }
    
    FOR(x,N) if(A[x]!=B[x]) return (void)_P("NO\n");
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%d %d %d\n",R[i].first.first+1,R[i].first.second+1,R[i].second);
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}