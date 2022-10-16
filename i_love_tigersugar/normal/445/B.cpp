#include<bits/stdc++.h>
#define MAX   55
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> g[MAX];
bool vst[MAX];
int n,m;
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void dfs(int u) {
    FORE(it,g[u]) if (!vst[*it]) {
        vst[*it]=true;
        dfs(*it);
    }
}
void process(void) {
    long long res=1LL<<n;
    FOR(i,1,n) if (!vst[i]) {
        res>>=1;
        vst[i]=true;
        dfs(i);
    }
    cout<<res;
}
int main(void) {
    loadgraph();
    process();
    return 0;
}