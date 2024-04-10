#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<ii> g[MAX];
bool blk[MAX];
int n,m;
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(i,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(ii(v,i));
        g[v].push_back(ii(u,i));
    }
    if (m&1) {
        printf("No solution");
        exit(0);
    }
}
int partition(int u) {
    vector<int> unpair;
    unpair.clear();
    FORE(it,g[u]) if (!blk[it->se]) {
        blk[it->se]=true;
        int v=it->fi;
        int w=partition(v);
        if (w>0) printf("%d %d %d\n",u,v,w);
        else unpair.push_back(v);
    }
    while (unpair.size()>1) {
        int v=unpair.back();unpair.pop_back();
        int w=unpair.back();unpair.pop_back();
        printf("%d %d %d\n",v,u,w);
    }
    if (!unpair.empty()) {
        int v=unpair.back();unpair.pop_back();
        return (v);
    }
    return (0);
}
int main(void) {
    loadgraph();
    return partition(1);
}