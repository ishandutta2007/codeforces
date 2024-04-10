#include<bits/stdc++.h>
#define MAXK   1313
#define MAXS   13
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
class DSU {
    private:
    vector<int> up;
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    public:
    DSU(){}
    DSU(int n) {
        up.assign(n+7,-1);
    }
    bool join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return (false);
        up[y]=x;
        return (true);
    }
};
struct edge {
    int u,v,c;
    edge() {
        u=v=c=0;
    }
    edge(int _u,int _v,int _c) {
        u=_u;v=_v;c=_c;
    }
    bool operator < (const edge &x) const {
        return (c<x.c);
    }
};
char a[MAXK][MAXS][MAXS];
int m,n,k,w;
vector<edge> v;
vector<int> g[MAXK];
int diff(int x,int y) {
    int ret=0;
    REP(i,m) REP(j,n) if (a[x][i][j]!=a[y][i][j]) ret++;
    return (ret);
}
void init(void) {
    scanf("%d%d%d%d",&m,&n,&k,&w);
    FOR(i,1,k) REP(j,m) scanf("%s",a[i][j]);
    FOR(i,1,k) FOR(j,i+1,k) v.push_back(edge(i,j,w*diff(i,j)));
    FOR(i,1,k) v.push_back(edge(0,i,m*n));
}
void kruskal(void) {
    DSU dsu=DSU(k+1);
    sort(v.begin(),v.end());
    int sum=0;
    FORE(it,v) if (dsu.join(it->u,it->v)) {
        sum+=it->c;
        g[it->u].push_back(it->v);
        g[it->v].push_back(it->u);
    }
    printf("%d\n",sum);
}
void dfs(int u,int p) {
    FORE(it,g[u]) if (*it!=p) {
        printf("%d %d\n",*it,u);
        dfs(*it,u);
    }
}
int main(void) {
    init();
    kruskal();
    dfs(0,-1);
    return 0;
}