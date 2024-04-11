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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

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

int N,M;
vector<pair<int,ll> > edge[201];
ll dist[201][201];

void solve() {
    int f,r,i,j,k,cur,tar,ret;
    ll l;
    int x,y,mx,my;
    
    MINUS(dist);
    GET2(&N,&M);
    FOR(i,M) {
        x=GETi()-1;
        y=GETi()-1;
        l=GETi()*4;
        edge[x].push_back(make_pair(y,l));
        edge[y].push_back(make_pair(x,l));
        dist[x][y]=dist[y][x]=l;
    }
    FOR(i,N) dist[i][i]=0;
    
    FOR(i,N) {
        FOR(j,N) FOR(k,N) {
            if(dist[j][i]>=0 && dist[i][k]>=0 && (dist[j][k]>dist[j][i]+dist[i][k] || dist[j][k]==-1))
                dist[j][k]=dist[j][i]+dist[i][k];
        }
    }
    
    ll mi=1LL<<40;
    //ten
    FOR(i,N) {
        ll ma=0;
        FOR(j,N) ma=max(ma,dist[i][j]);
        mi = min(mi, ma);
    }
    
    //hen
    vector<int> cand,maxd;
    FOR(i,N) {
        FOR(j,edge[i].size()) {
            int to=edge[i][j].first;
            if(to<i) continue;
            ll rl=edge[i][j].second;
            
            cand.clear();
            maxd.clear();
            cand.push_back(0);
            cand.push_back(rl);
            FOR(k,N) {
                if(abs(dist[i][k] - dist[to][k])<rl) 
                    cand.push_back((dist[i][k]+rl + dist[to][k])/2-(dist[i][k]));
            }
            
            sort(cand.begin(),cand.end());
            cand.erase(unique(cand.begin(),cand.end()),cand.end());
            if(cand.empty()) continue;
            
            FOR(k,cand.size()) {
                rl=cand[k];
                ll tl=0;
                FOR(f,N) {
                    tl = max(tl, min(dist[i][f]+rl,dist[to][f]+edge[i][j].second-rl));
                }
                maxd.push_back(tl);
                mi = min(mi,tl);
            }
            FOR(k,cand.size()-1) {
                if(cand[k+1]-cand[k] != abs(maxd[k+1]-maxd[k])) {
                    mi = min(mi,((ll)maxd[k+1]+maxd[k]-(cand[k+1]-cand[k]))/2);
                }
            }
            
            
            
        }
    }
    _P("%.10lf\n",mi/4.0);
    
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}