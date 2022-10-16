#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
vector<int> g[MAX];
int p[MAX];
int n;
int a[MAX],b[MAX];
vector<int> res;
void loadtree(void) {
    scanf("%d",&n);
    REP(zz,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
}
void dfs(int u,bool ev,bool od) {
    if (ev) a[u]^=1;
    bool use=(a[u]!=b[u]);
    if (use) res.push_back(u);
    FORE(it,g[u]) if (*it!=p[u]) {
        int v=*it;
        p[v]=u;
        dfs(v,od,ev^use);
    }
}
void process(void) {
    dfs(1,0,0);
    printf("%d\n",res.size());
    FORE(it,res) printf("%d\n",*it);
}
int main(void) {
    loadtree();
    process();
    return 0;
}