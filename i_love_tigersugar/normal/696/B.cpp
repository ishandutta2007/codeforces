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
vector<int> child[MAX];
int treeSize[MAX];
double res[MAX];
int n;
void loadTree(void) {
    scanf("%d",&n);
    FOR(i,2,n) {
        int x; scanf("%d",&x);
        child[x].push_back(i);
    }
}
void preDfs(int u) {
    treeSize[u]=1;
    FORE(it,child[u]) {
        preDfs(*it);
        treeSize[u]+=treeSize[*it];
    }
}
void dfs(int u) {
    FORE(it,child[u]) {
        res[*it]=res[u]+1+(treeSize[u]-1-treeSize[*it])*0.5;
        dfs(*it);
    }
}
void process(void) {
    preDfs(1);
    dfs(1);
    FOR(i,1,n) printf("%.7lf ",res[i]+1.0); printf("\n");
}
int main(void) {
    loadTree();
    process();
    return 0;
}