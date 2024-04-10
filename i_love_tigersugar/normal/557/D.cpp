#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> adj[MAX];
int dis[MAX],par[MAX],cntNode[MAX][2];
int n,m;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(int s) {
    queue<int> q;
    dis[s]=0;
    q.push(s);
    while (!q.empty()) {
        int u=q.front();q.pop();
        cntNode[s][dis[u]%2]++;
        FORE(it,adj[u]) if (dis[*it]<0) {
            dis[*it]=dis[u]+1;
            q.push(*it);
        }
    }
}
bool isBipharite(void) {
    memset(dis,-1,sizeof dis);
    FOR(i,1,n) if (dis[i]<0) bfs(i);
    FOR(u,1,n) FORE(it,adj[u]) if (dis[u]%2==dis[*it]%2) return (false);
    return (true);
}
void process(void) {
    if (m==0) {
        cout<<3<<" "<<1LL*n*(n-1)*(n-2)/6<<endl;
        return;
    }
    if (!isBipharite()) {
        printf("0 1\n");
        return;
    }
    bool have2=false;
    FOR(u,1,n) if (adj[u].size()>1) have2=true;
    if (have2) {
        long long cnt=0;
        FOR(u,1,n) REP(i,2) cnt+=1LL*cntNode[u][i]*(cntNode[u][i]-1)/2;
        cout<<1<<" "<<cnt<<endl;
    } else cout<<2<<" "<<1LL*m*(n-2)<<endl;
}
int main(void) {
    loadGraph();
    process();
    return 0;
}