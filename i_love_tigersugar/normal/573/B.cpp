#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
int d[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&d[i]);
    d[1]=d[n]=1;
}
void dijkstra(void) {
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    FOR(i,1,n) q.push(make_pair(d[i],i));
    while (!q.empty()) {
        int u=q.top().se;
        int w=q.top().fi;
        q.pop();
        if (d[u]<w) continue;
        for (int t=-1;t<=1;t=t+2) if (1<=u+t && u+t<=n) {
            int v=u+t;
            if (d[v]>d[u]+1) {
                d[v]=d[u]+1;
                q.push(make_pair(d[v],v));
            }
        }
    }
    int res=d[1];
    FOR(i,1,n) res=max(res,d[i]);
    printf("%d\n",res);
}
int main(void) {
    init();
    dijkstra();
    return 0;
}