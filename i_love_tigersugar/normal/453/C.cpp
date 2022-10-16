#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FORED(i,v) for (__typeof((v).rbegin()) i=(v).rbegin();i!=(v).rend();i++)
using namespace std;
vector<int> g[MAX],res;
int p[MAX],po[MAX],x[MAX];
int m,n;
bool od[MAX],vst[MAX];
inline void addver(int x) {
    od[x]=!od[x];
    res.push_back(x);
}
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok=true;
    FOR(i,1,n) {
        scanf("%d",&x[i]);
        if (x[i]) ok=false;
    }
    if (ok) {
        printf("0");
        exit(0);
    }
}
void gofr(int u) {
    vector<int> r;
    if (po[u]==0) return;
    //printf("DOWN %d\n",u);
    int v=po[u];
    while (u!=v) {
        r.push_back(u);
        u=p[u];
    }
    FORED(it,r) addver(*it);
}
void gobk(int u) {
    if (po[u]==0) return;
    //printf("UP %d\n",u);
    int v=po[u];
    while (u!=v) {
        u=p[u];
        addver(u);
    }
}
void dfs(int u) {
    //printf("VISIT %d\n",u);
    if (x[u]) gofr(u);
    FORE(it,g[u]) if (!vst[*it]) {
        int v=*it;
        vst[v]=true;
        p[v]=u;
        po[v]=x[u]?u:po[u];
        dfs(v);
    }
    if (x[u]) {
        gobk(u);
        if (!od[u]) {
            gofr(u);
            gobk(u);
        }
    }
}
void process(void) {
    int r;
    FOR(i,1,n) if (x[i]) {
        vst[i]=true;
        r=i;
        addver(r);
        dfs(i);
        break;
    }
    FOR(i,1,n) if (x[i] && !vst[i]) {
        printf("-1");
        return;
    }
    if (!od[r]) res.pop_back();
    printf("%d\n",res.size());
    FORE(it,res) printf("%d ",*it);
}
int main(void) {
    loadgraph();
    process();
    return 0;
}