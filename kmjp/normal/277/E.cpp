#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
pair<int,int> P[401];

template<class V_> class MinCostFlow {
public:
    struct edge { int to, capacity; V_ cost; int reve;};
    static const int MV = 5000;
    vector<edge> E[MV];
    V_ dist[MV],mav;
    int prev_v[MV], prev_e[MV], NV;
    
    MinCostFlow() { init(MV); mav=1e9;}
    void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
    void add_edge(int x,int y, int cap, V_ cost) {
        E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
        E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
    }
    
    V_ mincost(int from, int to, int flow) {
        V_ res=0;
        int i,v;
        ZERO(prev_v); ZERO(prev_e);
        while(flow>0) {
            fill(dist, dist+NV, mav);
            dist[from]=0;
            bool up=true;
            while(up) {
                up=false;
                FOR(v,NV) {
                    if(dist[v]==mav) continue;
                    FOR(i,E[v].size()) {
                        edge &e=E[v][i];
                        if(e.capacity>0 && dist[e.to]>dist[v]+e.cost+1e-9) {
                            dist[e.to]=dist[v]+e.cost;
                            prev_v[e.to]=v;
                            prev_e[e.to]=i;
                            up=true;
                        }
                    }
                }
            }
            if(dist[to]==mav) return -1;
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
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>P[i].second>>P[i].first;
    sort(P,P+N);
    if(P[N-1].first==P[N-2].first) return _P("-1\n");
    
    MinCostFlow<double> mcf;
    FOR(i,N) {
        mcf.add_edge(0,10+i*2,2,0);
        mcf.add_edge(10+i*2+1,1,1,0);
    }
    FOR(x,N) FOR(y,N) if(P[x].first>P[y].first) {
        double d=(P[y].second-P[x].second)*(P[y].second-P[x].second)+(P[y].first-P[x].first)*(P[y].first-P[x].first);
        mcf.add_edge(10+x*2,10+y*2+1,1,sqrt(d));
    }
    _P("%.9lf\n",mcf.mincost(0,1,N-1));
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}