#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for(__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
vector<int> g[MAX];
int a[MAX],p[MAX];
bool ins[MAX];
int n,m;
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
    ll join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return (0);
        ll ret=1LL*up[x]*up[y];
        up[x]+=up[y];
        up[y]=x;
        return (ret);
    }
};
DSU dsu;
bool cmp(int x,int y) {
    if (a[x]!=a[y]) return (a[x]>a[y]); else return (x<y);
}
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void process(void) {
    FOR(i,1,n) p[i]=i;
    sort(p+1,p+n+1,cmp);
    dsu=DSU(n);
    ll res=0LL;
    FOR(i,1,n) {
        int u=p[i];
        FORE(it,g[u]) if (ins[*it]) res+=dsu.join(u,*it)*a[u];
        ins[u]=true;
    }
    printf("%.7lf",2.0*res/n/(n-1));
}
int main(void) {
    loadgraph();
    process();
    return 0;
}