#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    Edge(int _u,int _v,int _c) {
        u=_u;v=_v;c=_c;
    }
    int change(int x) {
        int res=c-x;
        c=x;
        return (res);
    }
};
vector<int> g[MAX];
int n,q;
int par[MAX],nChild[MAX];
Edge edge[MAX];
double sumDis,toDivide;
void loadtree(void) {
    scanf("%d",&n);
    FOR(i,1,n-1) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        g[u].push_back(v);
        g[v].push_back(u);
        edge[i]=Edge(u,v,c);
    }
}
void dfs(int u) {
    nChild[u]=1;
    REP(i,g[u].size()) if (g[u][i]!=par[u]) {
        int v=g[u][i];
        par[v]=u;
        dfs(v);
        nChild[u]+=nChild[v];
    }
}
void process(void) {
    dfs(1);
    toDivide=1.0*n*(n-1)*(n-2)/6;
    FOR(i,1,n-1) {
        int u=edge[i].u;
        int v=edge[i].v;
        int ch=par[v]==u?v:u;
        sumDis+=1.0*edge[i].c*nChild[ch]*(n-nChild[ch]);
    }
    scanf("%d",&q);
    REP(zz,q) {
        int id,val;
        scanf("%d%d",&id,&val);
        int u=edge[id].u;
        int v=edge[id].v;
        int ch=par[v]==u?v:u;
        sumDis-=1.0*edge[id].change(val)*nChild[ch]*(n-nChild[ch]);
        printf("%.9lf\n",sumDis*(n-2)/toDivide);
    }
}
int main(void) {
    loadtree();
    process();
    return 0;
}