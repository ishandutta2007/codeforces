#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,pos[310000],fa[310000]; ll sum[310000];
vector<int> vec[310000]; bool vis[310000],ins[310000];
void upd(int u,int f){
    int mn=u,mx=u;
    while (u!=f){
        u=fa[u];
        mn=min(mn,u); mx=max(mx,u);
    }
    pos[mn]=min(pos[mn],mx);
}
void dfs(int u,int f){
    vis[u]=true; ins[u]=true; fa[u]=f; int v,i;
    for (int v:vec[u]){
        if (v==f) continue;
        if (!vis[v]) dfs(v,u);
        else if (ins[v]) upd(u,v);
    }
    ins[u]=false;
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(v); vec[v].push_back(u);
    }
    for (int i=1;i<=n+1;i++) pos[i]=n+1;
    for (int i=1;i<=n;i++)
        if (!vis[i]) dfs(i,0);
    for (int i=n;i>=1;i--){
        pos[i]=min(pos[i+1],pos[i]);
        sum[i]=sum[i+1]+(pos[i]-i);
    }
    scanf("%d",&q); int x,y;
    while (q--){
        scanf("%d%d",&x,&y);
        int l=x,r=y+1,mid;
        while (l<r){
            mid=(l+r)>>1;
            if (pos[mid]>y) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",sum[x]-sum[l]+1ll*(y-l+1)*(y-l+2)/2);//l,l+1,...y
    }
    return 0;
}