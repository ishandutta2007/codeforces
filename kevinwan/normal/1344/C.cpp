#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=3e5+10;
vector<int>g[mn],gg[mn];
bool vis[mn],ins[mn],bad;
int sa[mn],sb[mn];
void dfs1(int x){
    vis[x]=ins[x]=1;
    sb[x]=x;
    for(int y:g[x]){
        if(!vis[y])dfs1(y);
        else if(ins[y])bad=1;
        sb[x]=min(sb[x],sb[y]);
    }
    ins[x]=0;
}
void dfs2(int x){
    vis[x]=1;
    sa[x]=x;
    for(int y:gg[x]){
        if(!vis[y])dfs2(y);
        sa[x]=min(sa[x],sa[y]);
    }
}
bool ans[mn];
int a[mn],b[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(ans,1,sizeof(ans));
    for(int i=0;i<m;i++){
        scanf("%d%d",a+i,b+i);
        g[a[i]].push_back(b[i]);
    }
    for(int i=0;i<m;i++)gg[b[i]].push_back(a[i]);
    for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);
    if(bad){
        printf("-1");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)if(!vis[i])dfs2(i);
    for(int i=1;i<=n;i++)ans[i]=(sb[i]==i&&sa[i]==i);
    int pr=0;
    for(int i=1;i<=n;i++)pr+=ans[i];
    printf("%d\n",pr);
    for(int i=1;i<=n;i++){
        if(ans[i])printf("A");
        else printf("E");
    }
}