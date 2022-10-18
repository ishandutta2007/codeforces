#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
vector<int> adj[MAX];
int minVal[MAX],maxVal[MAX],cntLeaf[MAX];
int n;
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u,int p,int mode) {
    bool leaf=true;
    FORE(it,adj[u]) if (*it!=p) {
        leaf=false;
        int v=*it;
        dfs(v,u,mode^1);
        cntLeaf[u]+=cntLeaf[v];
    }
    if (leaf) {
        minVal[u]=maxVal[u]=cntLeaf[u]=1;
        return;
    }
    if (!mode) maxVal[u]=-INF; else minVal[u]=INF;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        if (!mode) {
            minVal[u]+=minVal[v];
            maxVal[u]=max(maxVal[u],cntLeaf[u]-cntLeaf[v]+maxVal[v]);
        } else {
            minVal[u]=min(minVal[u],minVal[v]);
            maxVal[u]+=maxVal[v]-1;
        }
    }
    if (mode) maxVal[u]++;
    //printf("At %d is %d %d\n",u,maxVal[u],minVal[u]);
}
void process(void) {
    dfs(1,-1,0);
    printf("%d %d\n",maxVal[1],minVal[1]);
}
int main(void) {
    loadTree();
    process();
    return 0;
}