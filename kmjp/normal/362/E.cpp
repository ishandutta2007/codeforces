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

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------


class MinCostFlow {
public:
    struct edge { int to, capacity; ll cost, reve;};
    static const int MV = 5000;
    vector<edge> E[MV];
    ll dist[MV], prev_v[MV], prev_e[MV], NV;
    
    void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
    void add_edge(int x,int y, int cap, int cost) {
        E[x].push_back((edge){y,cap,cost,E[y].size()});
        E[y].push_back((edge){x,0, -cost,E[x].size()-1}); /* rev edge */
    }
    
    int mincost(int from, int to, int flow) {
        int res=0,i,v;
        ZERO(prev_v); ZERO(prev_e);
        while(flow>0) {
            fill(dist, dist+NV, 1LL<<50);
            dist[from]=0;
            bool up=true;
            while(up) {
                up=false;
                FOR(v,NV) {
                    if(dist[v]==1LL<<50) continue;
                    FOR(i,E[v].size()) {
                        edge &e=E[v][i];
                        if(e.capacity>0 && dist[e.to]>dist[v]+e.cost) {
                            dist[e.to]=dist[v]+e.cost;
                            prev_v[e.to]=v;
                            prev_e[e.to]=i;
                            up=true;
                        }
                    }
                }
            }
            
            if(dist[to]==1LL<<50) return -1;
            int lc=flow;
            for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
            flow -= lc;
            res += lc*dist[to];
            for(v=to;v!=from;v=prev_v[v]) {
                edge &e=E[prev_v[v]][prev_e[v]];
                e.capacity -= lc;
                E[v][e.reve].capacity += lc;
            }
        }
        
        return res;
    }
};

void solve() {
    int f,i,j,k,l,x,y;
    int N,K;
    MinCostFlow mcf,mcf2;
    
    cin>>N>>K;
    mcf.init(N);
    FOR(y,N) FOR(x,N) {
        cin>>i;
        if(i) {
            mcf.add_edge(y,x,i,0);
            mcf.add_edge(y,x,1<<28,1);
        }
    }
    
    mcf2=mcf;
    if(mcf2.mincost(0,N-1,1)<0) return _P("0\n");
    
    mcf2=mcf;
    int lo=0,hi=1<<27;
    FOR(i,40) {
        int po=(lo+hi)/2;
        if(lo==hi) break;
        mcf=mcf2;
        if(mcf.mincost(0,N-1,po)>K) hi=po-1;
        else lo=po;
    }
    
    lo=max(0,lo-3);
    i=0;
    while(1) {
        mcf=mcf2;
        if(mcf.mincost(0,N-1,lo)>K) break;
        lo++;
    }
    _P("%d\n",lo-1);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}