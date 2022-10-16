#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
vector<int> g[MAX];
int f[MAX][2];
int n,col[MAX];
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void loadtree(void) {
    n=nextInt();
    REP(i,n-1) {
        int u=i+2;
        int v=nextInt()+1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    FOR(i,1,n) col[i]=nextInt();
}
void dfs(int u,int p) {
    int c[2];
    c[0]=1;c[1]=0;
    bool leaf=true;
    FORE(it,g[u]) if (*it!=p) {
        leaf=false;
        int v=*it;
        dfs(v,u);
        int pr[2];
        REP(i,2) pr[i]=c[i];
        c[0]=1LL*pr[0]*(f[v][0]+f[v][1])%mod;
        c[1]=(1LL*pr[1]*(f[v][0]+f[v][1])%mod+1LL*pr[0]*f[v][1]%mod)%mod;
    }
    if (leaf) {
        REP(i,2) f[u][i]=(col[u]==i);
    }
    else {
        if (col[u]) {
            f[u][0]=0;
            f[u][1]=c[0];
        }
        else {
            REP(i,2) f[u][i]=c[i];
        }
    }
}
void process(void) {
    dfs(1,-1);
    printf("%d",f[1][1]);
}
int main(void) {
    loadtree();
    process();
    return 0;
}