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

int N,Q,NP;
vector<int> E[200001];
vector<pair<int, int> > MP;
vector<vector<int> > P;


template<class V> class BIT {
public:
    int ME,BITL;
    vector<V> bit;
    
    int calcME(int v) {
        int t=1;
        while(t<v) t<<=1;
        init(t*2);
    }
    void init(int ME){
        this->ME=ME; bit.resize(ME); clear();
        BITL=0;
        while(ME>(1<<BITL)) BITL++;
    }
    void clear() {fill(bit.begin(),bit.end(),0);};
    
    // update L<=i<R
    void update(int cur,int L,int R,V v) {
        int bl=0;
        if(L==R) return;
        while(cur>=1<<(bl+1)) bl++;
        int tl=(cur-(1<<bl))<<(BITL-bl-1);
        int tr=(cur-(1<<bl)+1)<<(BITL-bl-1);
        int tm=(tl+tr)/2;
        
        if(tl==L && tr==R) {
            bit[cur]+=v;
            return;
        }
        if(L<tm) update((1<<(bl+1))+(tl>>(BITL-bl-2)),L,min(tm,R),v);
        if(R>=tm) update((1<<(bl+1))+(tm>>(BITL-bl-2)),max(L,tm),R,v);
    }
    void update(int L,int R,V v) { update(1,L,R,v);}
    
    V val(int entry) {
        V res=0;
        int i;
        FOR(i,BITL) res += bit[(1<<i)+(entry>>(BITL-i-1))];
        return res;
    }
};

BIT<int> TB[200001],MAS;



void dfs(int id, int cur, int pre) {
    MP[cur] = make_pair(id,P[id].size());
    P[id].push_back(cur);
    
    if(E[cur].size()==2) dfs(id,E[cur][0]+E[cur][1]-pre,cur);
    else TB[id].calcME(P[id].size()+3);
}

void add(int v,int x,int d) {
    if(v==0) {
        MAS.update(0,d+1,x);
    }
    else {
        pair<int, int> p = MP[v];
        if(p.second<d) {
            MAS.update(0,d-p.second,x);
            TB[p.first].update(d-p.second-1,min(p.second+d,(int)P[p.first].size())+1,x);
        }
        else {
            TB[p.first].update(p.second-d,min(p.second+d,(int)P[p.first].size())+1,x);
        }
    }
}

int get(int v) {
    if(v==0) {
        return MAS.val(0);
    }
    else {
        pair<int,int> p=MP[v];
        //_P("%d %d\n",TB[p.first].val(p.second),MAS.val(p.second+1));
        return TB[p.first].val(p.second)+MAS.val(p.second+1);
    }
}

void solve() {
    int f,r,i,j,k,l,x,y,z;
    ll re = 0;
    
    GET2(&N,&Q);
    FOR(i,N-1) {
        x=GETi()-1;
        y=GETi()-1;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    NP=E[0].size();
    MP.resize(N+1);
    P.resize(NP);
    MAS.calcME(N);
    FOR(i,NP) dfs(i,E[0][i],0);
    
    FOR(i,Q) {
        if(GETi()==0) {
            x=GETi()-1;
            y=GETi();
            z=GETi();
            add(x,y,z);
        }
        else {
            _P("%d\n",get(GETi()-1));
        }
        //FOR(i,N) _P("%d ",get(i));
        //_P("\n");
    }
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}