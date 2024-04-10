#include<bits/stdc++.h>
#define MAX   100100
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
class FenwickTree {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res+=v[x];
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    int getSum(int l,int r) const {
        return (l==1?get(r):get(r)-get(l-1));
    }
};
struct Edge {
    int u,v,type;
    Edge() {
        u=v=type=0;
    }
    Edge(int _u,int _v,int _type) {
        u=_u;v=_v;type=_type;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAX];
vector<int> adj[MAX];
int par[MAX][LOG+1],high[MAX],sta[MAX],fin[MAX];
int n,cnt;
FenwickTree cntUp,cntDown;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void loadTree(void) {
    scanf("%d",&n);
    REP(i,n-1) {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        edge[i]=Edge(u,v,t);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    high[0]=-1;
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,adj[u]) {
        int v=edge[*it].other(u);
        if (v!=par[u][0]) {
            par[v][0]=u;
            high[v]=high[u]+1;
            dfs(v);
        }
    }
    fin[u]=cnt;
}
void setupLCA(void) {
    dfs(1);
    FOR(j,1,LOG) FOR(i,1,n) par[i][j]=par[par[i][j-1]][j-1];
}
int LCA(int u,int v) {
    if (high[v]>high[u]) return (LCA(v,u));
    FORD(i,LOG,0) if (high[par[u][i]]>=high[v]) u=par[u][i];
    if (u==v) return (v);
    FORD(i,LOG,0) if (par[u][i]!=par[v][i]) {
        u=par[u][i];
        v=par[v][i];
    }
    return (par[u][0]);
}
void goUp(int u,int p) {
    if (u==p) return;
    //printf("Up %d %d\n",u,p);
    cntUp.update(sta[u],1);
    cntUp.update(sta[p],-1);
}
void goDown(int u,int p) {
    if (u==p) return;
    //printf("Down %d %d\n",u,p);
    cntDown.update(sta[u],1);
    cntDown.update(sta[p],-1);
}
void process(void) {
    cntUp=FenwickTree(n);
    cntDown=FenwickTree(n);
    int q;
    scanf("%d",&q);
    int u=1;
    REP(love,q) {
        int v;
        scanf("%d",&v);
        if (u==v) continue;
        int w=LCA(u,v);
        //printf("%d %d %d\n",u,v,w);
        goUp(u,w);
        goDown(v,w);
        u=v;
    }
    //FOR(i,1,n) printf("Up %d is %d\n",i,cntUp.getSum(sta[i],fin[i]));
    //FOR(i,1,n) printf("Down %d is %d\n",i,cntDown.getSum(sta[i],fin[i]));
    int sum=0;
    REP(i,n-1) if (edge[i].type==1) {
        int u=edge[i].u;
        int v=edge[i].v;
        int tmp=par[v][0]==u?cntUp.getSum(sta[v],fin[v]):cntDown.getSum(sta[u],fin[u]);
        //printf("cost %d %d %d\n",u,v,tmp);
        sum=(sum+pw(2,tmp))%mod;
        sum=(sum-1+mod)%mod;
    }
    printf("%d\n",sum);
}
int main(void) {
    loadTree();
    setupLCA();
    process();
    return 0;
}