#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,w,num,d[310000],fa[310000],x[310000];
int cnt,p[310000],ans,Ans[310000]; bool vis[310000];
vector<pii> vec[310000];
void dfs(int u,int f){
    if (d[u]==-1) w=u;
    else num^=d[u];
    fa[u]=f; vis[u]=true;
    int v,c;
    for (pii t:vec[u]){
        v=t.first; c=t.second;
        if (v==f||vis[v]) continue;
        x[v]=c; dfs(v,u);
    }
    p[++cnt]=u;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&d[i]);
    int u,v;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        vec[u].push_back(pii(v,i));
        vec[v].push_back(pii(u,i));
    }
    for (int i=1;i<=n;i++)
        if (!vis[i]){
            w=-1; num=0; cnt=0; dfs(i,0);
            if (num){
                if (w==-1){ puts("-1"); return 0;}
                d[w]=1;
            }
            for (int j=1;j<=cnt;j++)
                if (d[p[j]]==-1) d[p[j]]=0;
            for (int j=1;j<cnt;j++)
                if (d[p[j]]==1) d[fa[p[j]]]^=1,Ans[++ans]=x[p[j]];
        }
    printf("%d\n",ans);
    for (int i=1;i<=ans;i++) printf("%d ",Ans[i]);
    return 0;
}