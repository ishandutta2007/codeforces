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
int high[MAX];
vector<int> adj[MAX];
int n,m;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(high,-1,sizeof high);
}
void bfs(int s) {
    queue<int> q;
    high[s]=0;q.push(s);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FORE(it,adj[u]) if (high[*it]<0) {
            high[*it]=high[u]+1;
            q.push(*it);
        }
    }
}
void process(void) {
    FOR(i,1,n) if (high[i]<0) bfs(i);
    FOR(u,1,n) FORE(it,adj[u]) if ((high[u]-high[*it])%2==0) {
        printf("-1\n");
        return;
    }
    vector<int> v[2];
    FOR(i,1,n) v[high[i]%2].push_back(i);
    REP(i,2) {
        printf("%d\n",(int)v[i].size());
        FORE(it,v[i]) printf("%d ",*it); printf("\n");
    }
}
int main(void) {
    loadGraph();
    process();
    return 0;
}