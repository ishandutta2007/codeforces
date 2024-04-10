#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const long long INF=(long long)1e18+7LL;
vector<int> ch[MAX];
int a[MAX];
int n;
long long f[MAX][2];
void maximize(long long &a,const long long &b) {
    if (a<b) a=b;
}
void loadTree(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        int p;
        scanf("%d%d",&p,&a[i]);
        if (p>0) ch[p].push_back(i);
    }
}
void dfs(int u) {
    f[u][0]=0;
    f[u][1]=-INF;
    long long prev[2];
    FORE(it,ch[u]) {
        int v=*it;
        dfs(v);
        REP(i,2) prev[i]=f[u][i];
        REP(i,2) f[u][i]=-INF;
        REP(i,2) REP(j,2) maximize(f[u][i^j],prev[i]+f[v][j]);
    }
    maximize(f[u][1],f[u][0]+a[u]);
}
void process(void) {
    dfs(1);
    cout<<max(f[1][0],f[1][1])<<endl;
}
int main(void) {
    loadTree();
    process();
    return 0;
}