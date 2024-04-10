#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
vector<int> adj[MAX];
int n;
int f[MAX],res[MAX],prod[MAX],zero[MAX];
int inverse(int x) {
    assert(x!=0);
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void loadTree(void) {
    scanf("%d",&n);
    FOR(i,2,n) {
        int p;
        scanf("%d",&p);
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
}
void dfs1(int u,int p) {
    f[u]=prod[u]=1;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        dfs1(v,u);
        f[u]=1LL*f[u]*(f[v]+1)%mod;
        if ((f[v]+1)%mod==0) zero[u]++;
        else prod[u]=1LL*prod[u]*(f[v]+1)%mod;
    }
}
void dfs2(int u,int p,int val) {
    //printf("DFS %d %d %d\n",u,p,val);
    if (p<0) res[u]=f[u];
    else res[u]=1LL*f[u]*(val+1)%mod;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        int tmp;
        if ((f[v]+1)%mod==0) tmp=zero[u]==1?prod[u]:0;
        else tmp=1LL*f[u]*inverse((f[v]+1)%mod)%mod;
        dfs2(v,u,1LL*tmp*(val+1)%mod);
    }
}
void process(void) {
    dfs1(1,-1);
    dfs2(1,-1,0);
    FOR(i,1,n) {
        if (i>1) printf(" ");
        printf("%d",res[i]);
    }
    printf("\n");
}
int main(void) {
    loadTree();
    process();
    return 0;
}