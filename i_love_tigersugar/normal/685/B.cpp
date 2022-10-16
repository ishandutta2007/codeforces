#include<bits/stdc++.h>
#define MAX   300300
#define LOG   19
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
int n,q,numChild[MAX],bestChild[MAX];
int next[MAX][LOG+1];
void loadTree(void) {
    scanf("%d%d",&n,&q);
    FOR(i,2,n) {
        int x; scanf("%d",&x);
        child[x].push_back(i);
    }
}
void dfs(int u) {
    numChild[u]=1;
    FORE(it,child[u]) {
        int v=*it;
        dfs(v);
        numChild[u]+=numChild[v];
        if (numChild[bestChild[u]]<numChild[v]) bestChild[u]=v;
    }
}
void prepare(void) {
    dfs(1);
    FOR(i,1,n) next[i][0]=bestChild[i];
    FOR(j,1,LOG) FOR(i,1,n) next[i][j]=next[next[i][j-1]][j-1];
}
int centroid(int u) {
    int maxTreeSize=numChild[u]/2;
    if (numChild[bestChild[u]]<=maxTreeSize) return (u);
    int res=-1;
    FORD(i,LOG,0) if (next[u][i]>0) {
        if (numChild[bestChild[next[u][i]]]<=maxTreeSize) res=next[u][i];
        else u=next[u][i];
    }
    return (res);
}
void process(void) {
    REP(love,q) {
        int x; scanf("%d",&x);
        printf("%d\n",centroid(x));
    }
}
int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}