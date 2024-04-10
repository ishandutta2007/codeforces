#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define left    ___left
#define right    ___right
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
vector<int> adj[MAX];
int nLeaf[MAX];
int f[MAX][MAX][2];
int tmp[MAX][2];
int n;
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n==2) {
        printf("1\n");
        exit(0);
    }
    memset(f,0x3f,sizeof f);
}
void dfs(int u,int p) {
    bool leaf=true;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        dfs(v,u);
        leaf=false;
    }
    if (leaf) {
        nLeaf[u]=1;
        REP(i,2) f[u][i][i]=0;
        return;
    }
    REP(i,2) f[u][0][i]=0;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        REP(i,nLeaf[u]+1) REP(j,2) {
            tmp[i][j]=f[u][i][j];
            f[u][i][j]=INF;
        }
        REP(i,nLeaf[u]+1) REP(j,2) REP(k,nLeaf[v]+1) REP(l,2)
            minimize(f[u][i+k][j],tmp[i][j]+f[v][k][l]+(j!=l));
        nLeaf[u]+=nLeaf[v];
    }
}
void process(void) {
    FOR(i,1,n) if (adj[i].size()>1) {
        dfs(i,-1);
        printf("%d\n",min(f[i][nLeaf[i]/2][0],f[i][nLeaf[i]/2][1]));
        return;
    }
    assert(false);
}
int main(void) {
    loadTree();
    process();
    return 0;
}