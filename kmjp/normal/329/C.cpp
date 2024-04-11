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

int N,M;
vector<int> E[100001];
vector<pair<int, vector<int> > > V;
int vis[100001];
int mat[10][10];
vector<int> R,R2;
vector<int> S;

void dfs(int cur,vector<int>& VE) {
    int i;
    vis[cur]=1;
    VE.push_back(cur);
    FOR(i,E[cur].size()) if(vis[E[cur][i]]==0) dfs(E[cur][i],VE);
}

int connect(vector<int>& VE) {
    int i;
    int cur=VE[0];
    FOR(i,E[VE[0]].size()) if(E[VE[0]][i]==VE[VE.size()-1]) return 1;
    return 0;
}

void dfs2(int cur, int mask, int left) {
    int i,s=S.size();
    
    S.push_back(cur);
    if(left==0 || (left==1 && N==M)) {
        if(left==1 && N==M) {
            if(mat[S[S.size()-1]][1]) return;
            S.push_back(1);
        }
        FOR(i,S.size()-1) _P("%d %d\n",S[i],S[i+1]);
        exit(0);
    }
    
    FOR(i,N) {
        if(mask & (1<<i)) continue;
        if(mat[cur][i+1]) continue;
        dfs2(i+1,mask | (1<<i),left-1);
    }
    S.resize(s);
    
    
}


void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        E[x].push_back(y);
        E[y].push_back(x);
        if(N<10) mat[x][y]=mat[y][x]=1;
    }
    
    FOR(i,N) {
        if(vis[i+1]==0 && E[i+1].size()==1) {
            vector<int> VV;
            dfs(i+1,VV);
            V.push_back(make_pair(VV.size(),VV));
        }
    }
    FOR(i,N) {
        if(vis[i+1]==0) {
            vector<int> VV;
            dfs(i+1,VV);
            V.push_back(make_pair(VV.size(),VV));
        }
    }
    
    sort(V.begin(),V.end());
    vector<int> VL=V[V.size()-1].second;
    vector<vector<int> > V2;
    FOR(i,V.size()-1) V2.push_back(V[i].second);
    /*
    FOR(i,V.size()) {
        _P("%d:",V[i].first);
        FOR(j,V[i].second.size()) _P("%d,",V[i].second[j]);
        _P("\n");
    }
    */
    k=VL.size();
    FOR(j,V.size()-1) FOR(i,V[j].first) R2.push_back(V[j].second[i]);
    if(k<N-k || (k==N-k+1 && !connect(VL))) {
        FOR(i,k) {
            R.push_back(VL[i]);
            for(j=i;j<R2.size();j+=k) R.push_back(R2[j]);
        }
        
        FOR(i,M) _P("%d %d\n",R[i],R[(i+1)%N]);
        return;
    }
    
    if(k>=5) {
        if(k%2==0) swap(VL[VL.size()-1],VL[VL.size()-3]);
        FOR(i,k) {
            if(k%2==0) {
                if(i*2<k) R.push_back(VL[i*2]);
                else R.push_back(VL[i*2-k+1]);
            }
            else {
                R.push_back(VL[(i*2)%k]);
            }
            for(j=i;j<R2.size();j+=k) R.push_back(R2[j]);
        }
        FOR(i,M) _P("%d %d\n",R[i],R[(i+1)%N]);
        return;
    }
    
    FOR(i,N) {
        S.clear();
        dfs2(i+1,1<<i,M);
    }
    _P("-1\n");
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}