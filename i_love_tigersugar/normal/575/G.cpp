#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    Edge(int _u,int _v,int _c) {
        u=_u;v=_v;c=_c;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
Edge edge[MAX];
vector<int> adj[MAX];
vector<int> pathCost;
int n,m;
int dis[MAX],par[MAX],disZero[MAX],parZero[MAX];
pair<int,int> prevNode[MAX];
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(i,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        u++;v++;
        edge[i]=Edge(u,v,c);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    memset(dis,-1,sizeof dis);
    memset(disZero,-1,sizeof disZero);
    FOR(i,1,n) prevNode[i]=make_pair(-1,-1);
}
void bfs(int s,int dis[],int par[],bool zero) {
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) if (!zero || edge[*it].c==0) {
            int v=edge[*it].other(u);
            if (dis[v]<0) {
                par[v]=u;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    /*printf("BFS result\n");
    FOR(i,1,n) printf("%d %d\n",i,dis[i]);*/
}
void findAnswer(void) {
    bfs(1,dis,par,false);
    bfs(n,disZero,parZero,true);
    int minStep=MAX;
    FOR(i,1,n) if (disZero[i]>=0 && dis[i]>=0) minStep=min(minStep,dis[i]);
    assert(minStep<MAX);
    vector<int> can;
    FOR(i,1,n) if (disZero[i]>=0 && dis[i]==minStep) can.push_back(i);
    //printf("minStep %d\n",minStep);
    sort(ALL(can));
    can.resize(unique(ALL(can))-can.begin());
    FORE(it,can) prevNode[*it]=make_pair(disZero[*it],0);
    FOR(i,1,minStep) {
        assert(!can.empty());
        int minCost=10;
        FORE(it,can) FORE(jt,adj[*it]) {
            int u=edge[*jt].other(*it);
            if (dis[u]==minStep-i) minCost=min(minCost,edge[*jt].c);
        }
        assert(minCost<10);
        pathCost.push_back(minCost);
        vector<int> nextCan;
        FORE(it,can) FORE(jt,adj[*it]) if (edge[*jt].c==minCost) {
            int u=edge[*jt].other(*it);
            if (dis[u]==minStep-i) {
                nextCan.push_back(u);
                if (prevNode[u].se<0 || prevNode[u].fi>prevNode[*it].fi)
                    prevNode[u]=make_pair(prevNode[*it].fi,*it);
            }
        }
        sort(ALL(nextCan));
        nextCan.resize(unique(ALL(nextCan))-nextCan.begin());
        can=nextCan;
    }
    reverse(ALL(pathCost));
    while (pathCost.size()>1 && pathCost.back()==0) pathCost.pop_back();
    reverse(ALL(pathCost));
    if (pathCost.empty()) printf("0");
    FORE(it,pathCost) printf("%d",*it); printf("\n");
}
void tracePath(void) {
    vector<int> path;
    int cur=1;
    path.push_back(1);
    REP(love,pathCost.size()) {
        assert(prevNode[cur].se>=1);
        cur=prevNode[cur].se;
        path.push_back(cur);
    }
    REP(love,disZero[cur]) {
        assert(parZero[cur]>=1);
        cur=parZero[cur];
        path.push_back(cur);
    }
    printf("%d\n",(int)path.size());
    FORE(it,path) printf("%d ",*it-1); printf("\n");
}
int main(void) {
    loadGraph();
    findAnswer();
    tracePath();
    return 0;
}