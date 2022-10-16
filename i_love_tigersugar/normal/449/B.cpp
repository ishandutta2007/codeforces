#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
const int INF=(int)1e9+7;
vector<ii> g[MAX],h[MAX];
int minr[MAX];
ll d[MAX];
int res,n,m,q;
void loadgraph(void) {
    scanf("%d%d%d",&n,&m,&q);
    REP(zz,m) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(ii(w,v));
        g[v].push_back(ii(w,u));
        h[u].push_back(ii(w,v));
        h[v].push_back(ii(w,u));
    }
    memset(minr,0x3f,sizeof minr);
    REP(zz,q) {
        int u,w;
        scanf("%d%d",&u,&w);
        if (minr[u]<INF) res++;
        minr[u]=min(minr[u],w);
    }
    FOR(i,1,n) if (minr[i]<INF) {
        g[i].push_back(ii(minr[i],1));
        g[1].push_back(ii(minr[i],i));
    }
}
void dijkstra(void) {
    memset(d,0x3f,sizeof d);
    priority_queue<ii,vector<ii>,greater<ii> > q;
    d[1]=0;
    q.push(ii(0,1));
    while (!q.empty()) {
        int u=q.top().se;
        ll w=q.top().fi;
        q.pop();
        if (d[u]<w) continue;
        FORE(it,g[u]) {
            int v=it->se;
            if (w+it->fi<d[v]) {
                d[v]=w+it->fi;
                q.push(ii(d[v],v));
            }
        }
    }
}
bool cmp(int x,int y) {
    return (d[x]<d[y]);
}
void process(void) {
    vector<int> pos;
    FOR(i,1,n) pos.push_back(i);
    sort(pos.begin(),pos.end(),cmp);
    FORE(it,pos) {
        int u=*it;
        if (minr[u]>=INF) continue;
        bool del=false;
        FORE(it,h[u]) {
            int v=it->se;
            if (d[u]==d[v]+it->fi) {
                del=true;
                break;
            }
        }
        if (del) res++;
    }
    printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    loadgraph();
    dijkstra();
    process();
    return 0;
}