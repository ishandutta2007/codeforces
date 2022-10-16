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
int par[MAX],req[MAX],high[MAX],n;
vector<int> child[MAX];
void loadTree(void) {
    int m; scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v; scanf("%d%d",&u,&v);
        par[v]=u;
        child[u].push_back(v);
    }
    FOR(i,1,n) scanf("%d",&req[i]);
}
void dfs(int u) {
    FORE(it,child[u]) {
        int v=*it;
        high[v]=high[u]+1;
        if (req[v]!=req[u] && req[v]!=v) {
            printf("-1\n");
            exit(0);
        }
        dfs(*it);
    }
}
bool CompHigh(const int &x,const int &y) {
    return (high[x]>high[y]);
}
void process(void) {
    FOR(i,1,n) if (par[i]==0) dfs(i);
    vector<int> node;
    FOR(i,1,n) node.push_back(req[i]);
    sort(ALL(node));
    node.resize(unique(ALL(node))-node.begin());
    sort(ALL(node),CompHigh);
    printf("%d\n",(int)node.size());
    FORE(it,node) printf("%d\n",*it);
}
int main(void) {
    loadTree();
    process();
    return 0;
}