#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
vector<int>g[mn],ad[mn];
int c[mn];
bool vis[mn];
vector<int>pth;
void dfs1(int x){
    vis[x]=1;
    pth.push_back(x);
    for(int y:g[x]){
        if(!vis[y])dfs1(y),pth.push_back(x);
    }
}
void dfs2(int x){
    vis[x]=1;
    for(int y:g[x]){
        if(vis[y])continue;
        dfs2(y);
        if(c[y]){
            c[y]^=1,c[x]^=1;
            ad[x].push_back(y);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b),g[b].push_back(a);
    }
    int r=-1;
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1;i<=n;i++)if(c[i])r=i;
    if(r==-1){
        printf("0");
        return 0;
    }
    bool hail=0;
    dfs1(r);
    for(int i=1;i<=n;i++)if(!vis[i]&&c[i]){
        printf("-1");
        return 0;
    }
    for(int x:pth)c[x]^=1;
    int tot=0;
    for(int i=1;i<=n;i++)tot^=c[i];
    if(tot)c[r]^=1,pth.pop_back();
    memset(vis,0,sizeof(vis));
    dfs2(r);
    memset(vis,0,sizeof(vis));
    vector<int>ans;
    for(int x:pth){
        ans.push_back(x);
        if(!vis[x])for(int y:ad[x])ans.push_back(y),ans.push_back(x);
        vis[x]=1;
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}