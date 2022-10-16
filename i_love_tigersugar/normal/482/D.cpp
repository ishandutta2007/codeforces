#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
const int inv2=500000004;
vector<int> g[MAX];
int f[MAX][2];
int n;
void loadtree(void) {
    scanf("%d",&n);
    FOR(i,2,n) {
        int u;
        scanf("%d",&u);
        g[u].push_back(i);
    }
    FOR(i,1,n) sort(g[i].begin(),g[i].end());
}
int allSub(const vector<int> &v) {
    int res=1;
    FORE(it,v) res=1LL*res*(*it+1)%mod;
    return (res);
}
int allOddSub(const vector<int> &v) {
    int res=1;
    FORE(it,v) res=1LL*res*(1-*it+mod)%mod;
    return (1LL*(allSub(v)-res+mod)%mod*inv2%mod);
}
void dfs(int u) {
    REP(i,2) f[u][i]=i;
    int prev[2];
    vector<int> child[2];
    FORE(it,g[u]) {
        int v=*it;
        dfs(v);
        REP(i,2) child[i].push_back(f[v][i]);
        REP(i,2) prev[i]=f[u][i];
        REP(i,2) REP(j,2) f[u][i^j]=(f[u][i^j]+1LL*prev[i]*f[v][j])%mod;
    }
    if (g[u].size()<2) return;
    //printf("PRE F %d = %d\n",u,f[u]);
    REP(i,2) f[u][i]=2LL*f[u][i]%mod;
    f[u][0]=(f[u][0]-allOddSub(child[1])+mod)%mod;
    f[u][1]=(f[u][1]-allSub(child[0])+mod)%mod;
    //printf("F %d = %d\n",u,f[u]);
}
void process(void) {
    dfs(1);
    printf("%d",(f[1][0]+f[1][1])%mod);
}
int main(void) {
    assert(2LL*inv2%mod==1);
    loadtree();
    process();
    return 0;
}