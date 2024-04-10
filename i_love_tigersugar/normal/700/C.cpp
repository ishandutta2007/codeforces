#include<bits/stdc++.h>
#define MAXV   1010
#define MAXE   30030
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
const int INF=(int)2e9+7;
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&c);
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAXE];
vector<int> path,adj[MAXV];
int low[MAXV],num[MAXV],par[MAXV];
bool isBlocked[MAXE*2],isBridge[MAXE*2];
int bfsPar[MAXV];
int n,m,s,t,cnt;
void loadGraph(void) {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    FOR(i,1,m) edge[i].input();
    FOR(i,1,m) {
        adj[edge[i].u].push_back(i);
        adj[edge[i].v].push_back(i);
    }
}
void getPath(void) {
    memset(bfsPar,-1,sizeof bfsPar);
    queue<int> q;
    bfsPar[s]=0; q.push(s);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        FORE(it,adj[u]) {
            int v=edge[*it].other(u);
            if (bfsPar[v]<0) {
                bfsPar[v]=*it;
                q.push(v);
            }
        }
    }
    if (bfsPar[t]<0) {
        printf("0\n0\n");
        exit(0);
    }
    for (int u=t;u!=s;u=edge[bfsPar[u]].other(u)) path.push_back(bfsPar[u]);
}
int getEdgeID(int u,int edgeID) {
    if (edge[edgeID].u==u) return (edgeID*2);
    if (edge[edgeID].v==u) return (edgeID*2+1);
    assert(false);
}
void dfs(int u,int firstBlockEdge) {
    num[u]=++cnt;
    low[u]=n+1;
    FORE(it,adj[u]) if (*it!=firstBlockEdge) {
        int v=edge[*it].other(u);
        int tmp=getEdgeID(u,*it);
        if (!isBlocked[tmp]) {
            isBlocked[tmp^1]=true;
            if (num[v]==0) {
                dfs(v,firstBlockEdge);
                par[v]=tmp;
                isBridge[tmp]=low[v]>num[u];
                minimize(low[u],low[v]);
            } else minimize(low[u],num[v]);
        }
    }
}
int secondBlockEdge(int firstBlockEdge) {
    memset(low,0,sizeof low);
    memset(num,0,sizeof num);
    memset(par,-1,sizeof par);
    memset(isBlocked,false,sizeof isBlocked);
    memset(isBridge,false,sizeof isBridge);
    cnt=0;
    dfs(s,firstBlockEdge);
    if (par[t]<0) return (-1);
    int bestEdge=INF;
    for (int u=t;u!=s;u=edge[par[u]/2].other(u)) if (isBridge[par[u]]) {
        int tmp=par[u]/2;
        if (bestEdge>=INF || edge[bestEdge].c>edge[tmp].c) bestEdge=tmp;
    }
    return (bestEdge);
}
void process(void) {
    vector<int> bestEdge;
    int bestCost=INF;
    FORE(it,path) {
        int firstID=*it;
        int secondID=secondBlockEdge(firstID);
        if (secondID>=INF) continue;
        if (secondID<0) {
            if (bestCost<=edge[firstID].c) continue;
            bestCost=edge[firstID].c;
            bestEdge=vector<int>(1,firstID);
        } else {
            if (bestCost<=edge[firstID].c+edge[secondID].c) continue;
            bestCost=edge[firstID].c+edge[secondID].c;
            bestEdge=vector<int>(2,firstID);
            bestEdge[1]=secondID;
        }
    }
    if (bestCost>=INF) printf("-1\n");
    else {
        printf("%d\n%d\n",bestCost,(int)bestEdge.size());
        FORE(it,bestEdge) printf("%d ",*it); printf("\n");
    }
}
int main(void) {
    loadGraph();
    getPath();
    process();
    return 0;
}