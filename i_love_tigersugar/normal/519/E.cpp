#include<bits/stdc++.h>
#define MAX   100100
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1<<(i))
using namespace std;
vector<int> adj[MAX];
int par[MAX][LOG+1];
int high[MAX],nChild[MAX];
int n,q;
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    high[0]=-1;
}
void dfs(int u) {
    nChild[u]=1;
    FORE(it,adj[u]) if (*it!=par[u][0]) {
        int v=*it;
        high[v]=high[u]+1;
        par[v][0]=u;
        dfs(v);
        nChild[u]+=nChild[v];
    }
}
void prepare(void) {
    dfs(1);
    FOR(j,1,LOG) FOR(i,1,n) par[i][j]=par[par[i][j-1]][j-1];
}
int LCA(int u,int v) {
    if (high[u]<high[v]) return (LCA(v,u));
    FORD(i,LOG,0) if (high[par[u][i]]>=high[v]) u=par[u][i];
    if (u==v) return (u);
    FORD(i,LOG,0) if (par[u][i]!=par[v][i]) {
        u=par[u][i];
        v=par[v][i];
    }
    return (par[u][0]);
}
int jump(int u,int h) {
    FORD(i,LOG,0) if (h>=MASK(i)) {
        u=par[u][i];
        h-=MASK(i);
    }
    return (u);
}
int answer(int u,int v) {
    if (u==v) return (n);
    if ((high[u]+high[v])%2==1) return (0);
    int w=LCA(u,v);
    if (high[u]==high[v]) {
        int pu=jump(u,high[u]-high[w]-1);
        int pv=jump(v,high[v]-high[w]-1);
        return (n-nChild[pu]-nChild[pv]);
    }
    int dis=(high[u]+high[v]-2*high[w])/2;
    if (high[u]>high[v]) {
        int t=jump(u,dis);
        int pu=jump(u,dis-1);
        return (nChild[t]-nChild[pu]);
    } else {
        int t=jump(v,dis);
        int pv=jump(v,dis-1);
        return (nChild[t]-nChild[pv]);
    }
}
void process(void) {
    scanf("%d",&q);
    REP(love,q) {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",answer(u,v));
    }
}
int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}