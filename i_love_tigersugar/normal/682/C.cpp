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
vector<pair<int,int> > adj[MAX];
int val[MAX],n,res;
long long dist[MAX];
void loadTree(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&val[i]);
    REP(i,n-1) {
        int u,v,c; scanf("%d%d",&u,&c);
        v=i+2;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
}
void dfs(int u,int par,long long minDist,bool parRemove) {
    FORE(it,adj[u]) if (it->fi!=par) {
        int v=it->fi;
        dist[v]=dist[u]+it->se;
        bool needRemove=minDist<dist[v]-val[v];
        if (parRemove || needRemove) res++;
        dfs(v,u,min(minDist,dist[v]),parRemove || needRemove);
    }
}
void process(void) {
    dfs(1,-1,0,false);
    printf("%d\n",res);
}
int main(void) {
    loadTree();
    process();
    return 0;
}