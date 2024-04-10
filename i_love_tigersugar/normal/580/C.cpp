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
#define left    ___left
#define right    ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int n,m,cnt;
vector<int> adj[MAX];
int seq[MAX],maxSeq[MAX],have[MAX];
void loadTree(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&have[i]);
    REP(love,n-1) {
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u,int p) {
    bool leaf=true;
    FORE(it,adj[u]) if (*it!=p) {
        leaf=false;
        int v=*it;
        seq[v]=have[v]?seq[u]+1:0;
        maxSeq[v]=max(maxSeq[u],seq[v]);
        dfs(v,u);
    }
    if (leaf && maxSeq[u]<=m) cnt++;
}
void process(void) {
    seq[1]=maxSeq[1]=have[1];
    dfs(1,-1);
    printf("%d\n",cnt);
}
int main(void) {
    loadTree();
    process();
    return 0;
}