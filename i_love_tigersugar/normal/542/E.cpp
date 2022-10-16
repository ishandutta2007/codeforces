#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> adj[MAX];
int n,m,nComp;
int dist[MAX],compID[MAX],maxDist[MAX];
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void checkBipharite(int s,int compNum) {
    queue<int> q;
    dist[s]=0;
    compID[s]=compNum;
    q.push(s);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) if (dist[*it]<0) {
            dist[*it]=dist[u]+1;
            compID[*it]=compNum;
            q.push(*it);
        }
    }
}
void checkGraph(void) {
    memset(dist,-1,sizeof dist);
    FOR(i,1,n) if (dist[i]<0) checkBipharite(i,++nComp);
    FOR(u,1,n) FORE(it,adj[u]) if ((dist[u]-dist[*it])%2==0) {
        printf("-1\n");
        exit(0);
    }
}
int BFS(int s) {
    memset(dist,-1,sizeof dist);
    queue<int> q;
    dist[s]=0;
    q.push(s);
    int res=0;
    while (!q.empty()) {
        int u=q.front();q.pop();
        res=max(res,dist[u]);
        FORE(it,adj[u]) if (dist[*it]<0) {
            dist[*it]=dist[u]+1;
            q.push(*it);
        }
    }
    return (res);
}
void process(void) {
    FOR(i,1,n) maxDist[compID[i]]=max(maxDist[compID[i]],BFS(i));
    int res=0;
    FOR(i,1,nComp) res+=maxDist[i];
    printf("%d\n",res);
}
int main(void) {
    loadGraph();
    checkGraph();
    process();
    return 0;
}