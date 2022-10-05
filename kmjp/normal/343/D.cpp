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

int N,Q,ID;
int L[500010],R[500010],IDs[500010];
const int NNV=1<<20;
vector<int> E[500010];


// rangecomp
template<class V,int NV> class SegTree_1 {
public:
    vector<V> val;
    V comp(V l,V r){ return max(l,r);};
    
    SegTree_1(){val.resize(NV*2); clear();};
    void clear() { int i; FOR(i,NV*2) val[i]=0;}
    
    V getval(int x,int y,int l,int r,int k) {
        if(r<=x || y<=l) return 0;
        if(x<=l && r<=y) return val[k];
        return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
    }
    V getval(int x,int y) { return getval(x,y,0,NV,1);}
    void debug() {
        _P("[%d] ",val[1]);
        for(int i=2;i<NV*2;i++) {
            if((i&(i-1))==0) _P("[%d",val[i]);
            else if((i&(i+1))==0) _P(" %d] ",val[i]);
            else _P(" %d",val[i]);
        }
        _P("\n");
    }
    void update(int entry, V v) {
        entry += NV;
        val[entry]=v;
        while(entry>1) {
            //if(Q==100000 && entry<128) _P("%d ",entry);
            entry>>=1;
            val[entry]=comp(val[entry*2],val[entry*2+1]);
        }
        //if(Q==100000) _P("::\na\n");
    }
};

// range
template<class V,int NV> class SegTree_2 {
public:
    V nolink;
    vector<V> val;
    SegTree_2(){val.resize(NV*2); clear(); nolink=-1<<30;};
    void clear() { for(int i=0;i<NV*2;i++) val[i]=0; }
    
    V getval(int k) {
        int e=1;
        while(val[e]==nolink) e=e*2+(((k*2)&NV)>0), k*=2;
        return val[e];
    }
    void debug() {
        _P("[%d] ",val[1]);
        for(int i=2;i<NV*2;i++) {
            if((i&(i-1))==0) _P("[%d",val[i]);
            else if((i&(i+1))==0) _P(" %d] ",val[i]);
            else _P(" %d",val[i]);
        }
        _P("\n");
    }
    
    void update(int x,int y,int l,int r, V v,int k) {
        if(l>=r) return;
        if(x<=l && r<=y) val[k]=v;
        else if(l < y && x < r) {
            if(val[k]!=nolink) {
                val[k*2]=val[k*2+1]=val[k];
                val[k]=nolink;
            }
            update(x,y,l,(l+r)/2,v,k*2);
            update(x,y,(l+r)/2,r,v,k*2+1);
        }
    }
    void update(int x,int y,V v) { update(x,y,0,NV,v,1);}
    
};


int dfs(int cur,int pre) {
    int i;
    IDs[ID]=cur;
    L[cur]=ID++;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(tar!=pre) dfs(tar,cur);
    }
    R[cur]=ID;
}

void solve() {
    int f,r,i,j,k,l, x,y;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    
    dfs(0,-1);
    
    SegTree_2<int,NNV> st_on;
    SegTree_1<int,NNV> st_off;
    
    st_on.update(0,NNV,0);
    FOR(i,NNV) st_off.update(i,1);

    cin>>Q;
    FOR(i,Q) {
        cin>>x>>y;
        y--;
        if(x==1) st_on.update(L[y],R[y],i+2);
        else if(x==2) st_off.update(L[y],i+2);
        else {
            if(st_off.getval(L[y],R[y])>st_on.getval(L[y])) _P("0\n");
            else _P("1\n");
        }
    }
    
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}