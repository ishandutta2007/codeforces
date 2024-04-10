// Hydro submission #61891d511edf93b3ad6589d1@1636375889977
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int n,m,ans,S,T;
struct node {int y,v,to;}e[1000010];
int tot=0,Head[N];
void add(int x,int y,int v) {
	e[++tot]=(node){y,v,Head[x]};
	Head[x]=tot;
}
int d[N],vis[N];
priority_queue<pair<int,int> > q;
void dij(int s) {
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0; q.push(make_pair(0,s));
    while (q.size()) {
        int x=q.top().second; q.pop();
        if (vis[x]) continue; vis[x]=1;
        for (int i=Head[x];i;i=e[i].to) {
            int y=e[i].y,v=e[i].v;
            if (d[y]>d[x]+v) {
                d[y]=d[x]+v;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
signed main() {
    scanf("%lld%lld",&n,&m);
    for (int i=1,u,v,w;i<=m;i++) {
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w*2),add(v,u,w*2);
    }
    for (int i=1,w;i<=n;i++) {
        scanf("%lld",&w);
        add(i,n+1,w),add(n+1,i,w);
    }
    dij(n+1);
    for (int i=1;i<=n;i++) {
        printf("%lld ",d[i]);
    }
    return 0;
}