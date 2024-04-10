#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const long long INF=(long long)1e18+7LL;
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&c);
    }
    int other(int x) const {
        return (u^v^x);
    }
};
Edge edge[MAX];
vector<int> adj[MAX];
bool canStart[MAX];
int n,m,q;
long long dis[MAX];
void loadGraph(void) {
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,m) {
        edge[i].input();
        adj[edge[i].u].push_back(i);
        adj[edge[i].v].push_back(i);
    }
    REP(love,q) {
        int x; scanf("%d",&x);
        canStart[x]=true;
    }
}
void dijkstra(void) {
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
    memset(dis,0x3f,sizeof dis);
    FOR(i,1,n) if (canStart[i]) dis[i]=0;
    FOR(i,1,n) if (canStart[i]) q.push(make_pair(0,i));
    while (!q.empty()) {
        long long d=q.top().fi;
        int u=q.top().se;
        q.pop();
        if (dis[u]<d) continue;
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (dis[v]>dis[u]+edge[*it].c) {
                dis[v]=dis[u]+edge[*it].c;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    long long res=INF;
    FOR(i,1,n) if (!canStart[i]) minimize(res,dis[i]);
    cout<<(res<INF?res:-1LL)<<endl;
}
int main(void) {
    loadGraph();
    dijkstra();
    return 0;
}