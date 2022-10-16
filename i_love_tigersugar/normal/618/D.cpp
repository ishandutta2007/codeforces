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
int f[MAX][5];
int n,x,y;
void loadTree(void) {
    scanf("%d%d%d",&n,&x,&y);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int minEdgeCase(void) {
    FOR(i,1,n) if (adj[i].size()==n-1) return (1);
    return (0);
}
void dfs(int u,int p) {
    f[u][0]=0;
    f[u][1]=f[u][2]=-1;
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        dfs(v,u);
        int prev[5];
        REP(i,3) prev[i]=f[u][i];
        REP(i,3) f[u][i]=-1;
        REP(i,3) if (prev[i]>=0) REP(j,3) if (f[v][j]>=0) {
            maximize(f[u][i],prev[i]+f[v][j]);
            if (i+1<3 && j+1<3) maximize(f[u][i+1],prev[i]+f[v][j]+1);
        }
    }
}
int maxEdgeCase(void) {
    dfs(1,-1);
    int res=-1;
    REP(i,3) maximize(res,f[1][i]);
    return (res);
}
void process(void) {
/*    if (n==2) {
        cout<<x<<endl;
        exit(0);
    }*/
    if (x==y) {
        cout<<1LL*x*(n-1)<<endl;
        exit(0);
    } else if (x<y) {
        int t=maxEdgeCase();
        cout<<1LL*t*x+1LL*(n-1-t)*y<<endl;
        exit(0);
    } else {
        int t=minEdgeCase();
        cout<<1LL*t*x+1LL*(n-1-t)*y<<endl;
        exit(0);
    }
}
int main(void) {
    loadTree();
    process();
    return 0;
}