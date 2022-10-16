#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
vector<int> adj[MAX];
int n,m,cnt;
int topo[MAX],order[MAX];
bool vst[MAX];
map<pair<int,int>,int> edgeID;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        edgeID[make_pair(u,v)]=i;
    }
}
void dfs(int u) {
    vst[u]=true;
    FORE(it,adj[u]) if (!vst[*it]) dfs(*it);
    topo[u]=--cnt;
}
bool Comp(const int &x,const int &y) {
    return (topo[x]<topo[y]);
}
void process(void) {
    memset(topo,-1,sizeof topo);
    cnt=n+7;
    FOR(i,1,n) if (topo[i]<0) dfs(i);
    FOR(i,1,n) order[i]=i;
    sort(order+1,order+n+1,Comp);
    int res=0;
    FOR(i,1,n-1) {
        int u=order[i];
        int v=order[i+1];
        if (edgeID.find(make_pair(u,v))==edgeID.end()) {
            printf("-1\n");
            return;
        }
        maximize(res,edgeID[make_pair(u,v)]);
    }
    printf("%d\n",res);
}
int main(void) {
    loadGraph();
    process();
    return 0;
}