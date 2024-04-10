//This code is based on MLGuy's solution
#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
vector<int> g[MAX];
int n,delta;
int a[MAX];
void loadtree(void) {
    scanf("%d%d",&delta,&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    REP(zz,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
int dfs(int u,int par,int root) {
    int res=1;
    FORE(it,g[u]) if (*it!=par) {
        int v=*it;
        if (a[root]<=a[v] && a[v]<=a[root]+delta && (a[root]<a[v] || root<v))
            res=1LL*res*(dfs(v,u,root)+1)%mod;
    }
    return (res);
}
void process(void) {
    int res=0;
    FOR(i,1,n) res=(res+dfs(i,-1,i))%mod;
    printf("%d",res);
}
int main(void) {
    loadtree();
    process();
    return 0;
}