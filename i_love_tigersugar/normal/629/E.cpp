#include<bits/stdc++.h>
#define MAX   100100
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
vector<int> adj[MAX];
int par[MAX][LOG+1],high[MAX],numChild[MAX];
long long sumHigh[MAX],sumDis[MAX];
int n,q;
void loadTree(void) {
    scanf("%d%d",&n,&q);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    high[0]=-1;
}
void dfs(int u) {
    sumHigh[u]=high[u];
    numChild[u]=1;
    FORE(it,adj[u]) if (*it!=par[u][0]) {
        int v=*it;
        par[v][0]=u;
        high[v]=high[u]+1;
        dfs(v);
        sumHigh[u]+=sumHigh[v];
        numChild[u]+=numChild[v];
    }
}
void DFS(int u) {
    FORE(it,adj[u]) if (*it!=par[u][0]) {
        int v=*it;
        sumDis[v]=sumDis[u]+n-2*numChild[v];
        DFS(v);
    }
}
void setupLCA(void) {
    dfs(1);
    FOR(i,1,n) sumDis[1]+=high[i];
    DFS(1);
    FOR(j,1,LOG) FOR(i,1,n) par[i][j]=par[par[i][j-1]][j-1];
}
int jump(int u,int h) {
    FORD(i,LOG,0) if (MASK(i)<=h) {
        u=par[u][i];
        h-=MASK(i);
    }
    return (u);
}
int LCA(int u,int v) {
    if (high[v]>high[u]) return (LCA(v,u));
    FORD(i,LOG,0) if (high[par[u][i]]>=high[v]) u=par[u][i];
    if (u==v) return (u);
    FORD(i,LOG,0) if (par[u][i]!=par[v][i]) {
        u=par[u][i];
        v=par[v][i];
    }
    return (par[u][0]);
}
double query(int u,int v) {
    int w=LCA(u,v);
    if (w!=u && w!=v) return (1.0*sumHigh[u]/numChild[u]+1.0*sumHigh[v]/numChild[v]-2*high[w]+1);
    if (w==v) return (query(v,u));
    int t=jump(v,high[v]-high[u]-1);
    long long sumU=sumDis[u]-(sumHigh[t]-1LL*high[u]*numChild[t]);
    int numU=n-numChild[t];
    return (1.0*sumU/numU+1.0*sumHigh[v]/numChild[v]-high[u]+1);
}
void process(void) {
    REP(love,q) {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%.10000lf\n",query(u,v));
    }
}
int main(void) {
    loadTree();
    setupLCA();
    process();
    return 0;
}