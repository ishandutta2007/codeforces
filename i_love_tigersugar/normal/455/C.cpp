#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
inline int Max(int x,int y,int z) {
    return (max(x,max(y,z)));
}
class DSU {
    public:
    struct node {
        int up,root,maxdis,leaf;
        node() {
            up=root=maxdis=leaf=0;
        }
        node(int x) {
            up=-1;
            root=x;
            maxdis=0;
            leaf=0;
        }
    };
    void merge(node &x,node &y) {
        int t=Max(x.maxdis,y.maxdis,x.leaf+y.leaf+1);
        if (t!=x.maxdis) {
            if (t==y.maxdis) {
                x.root=y.root;
                x.leaf=y.leaf;
            }
            else {
                if (y.leaf>x.leaf) {
                    x.root=y.root;
                    x.leaf=y.leaf;
                }
                else if (y.leaf==x.leaf) x.leaf++;
            }
        }
        x.maxdis=t;
    }
    vector<node> v;
    int find(int x) {
        if (v[x].up<0) return (x);
        v[x].up=find(v[x].up);
        return (v[x].up);
    }
    DSU(){}
    DSU(int n) {
        v.push_back(node());
        FOR(i,1,n) v.push_back(node(i));
    }
    void join(int a,int b,bool mode) {
        int x=find(a);
        int y=find(b);
        if (x==y) return;
        v[y].up=x;
        if (mode) merge(v[x],v[y]);
    }
    int query(int x) {
        return (v[find(x)].maxdis);
    }
};
DSU dsu;
int n,m,q;
vector<int> g[MAX];
int vst[MAX],h[MAX],p[MAX];
void init(void) {
    scanf("%d%d%d",&n,&m,&q);
    dsu=DSU(n);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        dsu.join(u,v,false);
    }
}
int bfs(int s) {
    vector<int> del;
    queue<int> q;
    vst[s]=true;
    h[s]=0;
    del.push_back(s);
    q.push(s);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,g[u]) if (!vst[*it]) {
            int v=*it;
            vst[v]=true;
            h[v]=h[u]+1;
            p[v]=u;
            q.push(v);
            del.push_back(v);
        }
    }
    FORE(it,del) vst[*it]=false;
    int res=s;
    FORE(it,del) if (h[*it]>h[res]) res=*it;
    return (res);
}
void precount(void) {
    FOR(i,1,n) if (dsu.v[i].up<0) {
        int t=bfs(i);
        //printf("%d\n",t);
        t=bfs(t);
        //printf("BFS of %d is %d %d\n",i,t,h[t]);
        dsu.v[i].maxdis=h[t];
        dsu.v[i].leaf=(h[t]+1)/2;
        REP(zz,dsu.v[i].leaf) t=p[t];
        dsu.v[i].root=t;
        //printf("PROP %d %d %d\n",dsu.v[i].maxdis,dsu.v[i].leaf,dsu.v[i].root);
    }
}
void process(void) {
    REP(zz,q) {
        int t,u,v;
        scanf("%d%d",&t,&u);
        if (t==2) scanf("%d",&v);
        if (t==1) printf("%d\n",dsu.query(u));
        else dsu.join(u,v,true);
    }
}
int main(void) {
    init();
    precount();
    process();
    return 0;
}