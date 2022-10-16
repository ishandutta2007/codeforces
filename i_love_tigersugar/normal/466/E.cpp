#include<cstdio>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
class DSU {
    private:
    vector<int> up;
    public:
    DSU(){}
    DSU(int n) {
        up.assign(n+7,-1);
    }
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    void join(int u,int v) {
        up[find(v)]=find(u);
    }
};
struct query {
    int t,x,y;
    query() {
        t=x=y=0;
    }
    void input(void) {
        scanf("%d%d",&t,&x);
        if (t!=2) scanf("%d",&y);
    }
};
struct doc {
    int u;
    vector<int> ask;
    doc() {
        u=0;
    }
    doc(int _u) {
        u=_u;
    }
};
DSU dsu;
vector<int> ch[MAX];
int sta[MAX],fin[MAX];
query que[MAX];
vector<doc> ad;
int n,q,cnt;
bool ans[MAX],isroot[MAX];
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) isroot[i]=true;
    FOR(i,1,q) que[i].input();
    FOR(i,1,q) {
        if (que[i].t==1) {
            ch[que[i].y].push_back(que[i].x);
            isroot[que[i].x]=false;
        }
        if (que[i].t==2) ad.push_back(doc(que[i].x));
        if (que[i].t==3) ad[que[i].y-1].ask.push_back(i);
    }
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,ch[u]) dfs(*it);
    fin[u]=cnt;
}
inline bool isparent(int u,int v) {
    return (sta[u]<=sta[v] && fin[v]<=fin[u]);
}
void process(void) {
    FOR(i,1,n) if (isroot[i]) dfs(i);
    dsu=DSU(n);
    int nd=0;
    FOR(i,1,q) {
        if (que[i].t==1) dsu.join(que[i].y,que[i].x);
        if (que[i].t==2) {
            int v=que[i].x;
            int u=dsu.find(v);
            FORE(it,ad[nd].ask) ans[*it]=(isparent(u,que[*it].x) && isparent(que[*it].x,v));
            nd++;
        }
    }
    FOR(i,1,q) if (que[i].t==3) printf("%s\n",ans[i]?"YES":"NO");
}
int main(void) {
    init();
    process();
    return 0;
}