#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
#define SQR(x) ((x)*(x))
using namespace std;
typedef pair<int,int> ii;
class DSU {
    public:
    vector<int> up;
    DSU(){}
    DSU(int n) {
        up.assign(n+7,-1);
    }
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    void join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return;
        up[x]+=up[y];
        up[y]=x;
    }
};
vector<ii> g[MAX];
int low[MAX],num[MAX];
bool block[MAX*MAX*2],isBridge[MAX*MAX*2];
int n,m,nComp,cnt;
vector<int> tree[MAX];
int compSZ[MAX],compID[MAX];
int treeSZ[MAX],nPair[MAX];
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(i,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(ii(v,i*2));
        g[v].push_back(ii(u,i*2+1));
    }
}
void visit(int u) {
    num[u]=++cnt;
    low[u]=n+1;
    FORE(it,g[u]) if (!block[it->se]) {
        int v=it->fi;
        block[it->se^1]=true;
        if (num[v]==0) {
            visit(v);
            if (low[v]>num[u]) isBridge[it->se]=true;
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}
void loadtree(void) {
    FOR(i,1,n) if (num[i]==0) visit(i);
    DSU dsu(n);
    FOR(u,1,n) FORE(it,g[u]) if (!isBridge[it->se] && !isBridge[it->se^1]) dsu.join(u,it->fi);
    FOR(i,1,n) if (dsu.up[i]<0) {
        nComp++;
        compID[i]=nComp;
        compSZ[nComp]=-dsu.up[i];
    }
    FOR(u,1,n) FORE(it,g[u]) if (isBridge[it->se]) {
        int v=it->fi;
        int x=compID[dsu.find(u)];
        int y=compID[dsu.find(v)];
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
}
void dfs(int u,int p) {
    treeSZ[u]=compSZ[u];
    nPair[u]=SQR(treeSZ[u]);
    FORE(it,tree[u]) if (*it!=p) {
        int v=*it;
        dfs(v,u);
        treeSZ[u]+=treeSZ[v];
        nPair[u]+=nPair[v]+treeSZ[v]*compSZ[u];
    }
}
bool dp[MAX][MAX];
int maxProduct(const vector<int> &v) {
    REP(i,v.size()+1) REP(j,n+1) dp[i][j]=false;
    dp[0][0]=true;
    REP(i,v.size()) REP(j,n+1) if (dp[i][j]) {
        dp[i+1][j]=true;
        dp[i+1][j+v[i]]=true;
    }
    int res=0;
    int sum=0;
    FORE(it,v) sum+=*it;
    REP(j,n+1) if (dp[v.size()][j]) res=max(res,j*(sum-j));
    return (res);
}
int chooseRoot(int u) {
    dfs(u,-1);
    vector<int> tmp;
    FORE(it,tree[u]) tmp.push_back(treeSZ[*it]);
    return (nPair[u]+maxProduct(tmp));
}
void process(void) {
    int res=0;
    FOR(i,1,nComp) res=max(res,chooseRoot(i));
    printf("%d",res);
}
int main(void) {
    loadgraph();
    loadtree();
    process();
    return 0;
}