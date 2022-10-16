#include<bits/stdc++.h>
#define MAX   200200
#define LOG   18
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
vector<int> adj[MAX];
int par[MAX][LOG+1],high[MAX],sta[MAX],fin[MAX];
int n,cnt;
vector<int> spanNode,spanChild[MAX];
int spanPar[MAX],spanRoot,numFake;
bool important[MAX];
int f[MAX][2];
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,adj[u]) if (*it!=par[u][0]) {
        int v=*it;
        par[v][0]=u;
        high[v]=high[u]+1;
        dfs(v);
    }
    fin[u]=cnt;
}
void prepare(void) {
    high[0]=-1;
    dfs(1);
    FOR(j,1,LOG) FOR(i,1,n) par[i][j]=par[par[i][j-1]][j-1];
}
bool CompDFS(int u,int v) {
    return (sta[u]<sta[v]);
}
bool isParent(int u,int v) {
    return (sta[u]<=sta[v] && sta[v]<=fin[u]);
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
void buildSpanTree(void) {
    vector<int> impNode;
    int m; scanf("%d",&m);
    REP(love,m) {
        int x; scanf("%d",&x);
        impNode.push_back(x);
        important[x]=true;
    }
    sort(ALL(impNode),CompDFS);
    FORE(it,impNode) spanNode.push_back(*it);
    REP(i,(int)impNode.size()-1) spanNode.push_back(LCA(impNode[i],impNode[i+1]));
    sort(ALL(spanNode),CompDFS);
    spanNode.resize(unique(ALL(spanNode))-spanNode.begin());
    spanRoot=spanNode[0];
    FOR(i,1,(int)spanNode.size()-1) {
        int cur=spanNode[i];
        int tmp=spanNode[i-1];
        while (!isParent(tmp,cur)) tmp=spanPar[tmp];
        spanPar[cur]=tmp;
    }
    FOR(i,1,(int)spanNode.size()-1) {
        int cur=spanNode[i];
        int par=spanPar[cur];
        if (high[cur]-high[par]==1) spanChild[par].push_back(cur);
        else {
            numFake++;
            int fake=n+numFake;
            spanChild[par].push_back(fake);
            spanChild[fake].push_back(cur);
        }
    }
}
void spanDFS(int u) {
    int dp[3];
    REP(i,2) f[u][i]=INF;
    REP(i,3) dp[i]=INF;
    dp[0]=0;
    FORE(it,spanChild[u]) {
        int v=*it;
        spanDFS(v);
        int newDP[3];
        REP(i,3) newDP[i]=INF;
        REP(i,3) REP(j,2) minimize(newDP[min(i+j,2)],dp[i]+f[v][j]);
        REP(i,3) dp[i]=newDP[i];
    }
    if (!important[u]) REP(i,3) minimize(f[u][0],dp[i]+1);
    minimize(f[u][important[u]],dp[0]);
    if (!important[u]) minimize(f[u][1],dp[1]);
}
void clearSpanTree(void) {
    FORE(it,spanNode) {
        spanChild[*it].clear();
        spanPar[*it]=important[*it]=false;
    }
    FOR(i,n+1,n+numFake) {
        spanChild[i].clear();
        spanPar[i]=important[i]=false;
    }
    spanRoot=numFake=0;
    spanNode.clear();
}
void process(void) {
    int q; scanf("%d",&q);
    REP(love,q) {
        buildSpanTree();
        spanDFS(spanRoot);
        int res=min(f[spanRoot][0],f[spanRoot][1]);
        printf("%d\n",res<INF?res:-1);
        clearSpanTree();
    }
}
int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}