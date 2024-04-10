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
int next[MAX],dis[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&next[i]);
}
void bfs(void) {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    dis[1]=0; q.push(1);
    while (!q.empty()) {
        int u=q.front();q.pop();
        FOR(v,u-1,u+1) if (1<=v && v<=n && dis[v]>dis[u]+1) {
            dis[v]=dis[u]+1;
            q.push(v);
        }
        if (dis[next[u]]>dis[u]+1) {
            dis[next[u]]=dis[u]+1;
            q.push(next[u]);
        }
    }
    FOR(i,1,n) printf("%d ",dis[i]); printf("\n");
}
int main(void) {
    init();
    bfs();
    return 0;
}