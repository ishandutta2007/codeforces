#include <bits/stdc++.h>
using namespace std;
const int mn=5e5+10;
vector<int>g[mn];
vector<int>ind[mn];
vector<int>me,is;
bool vis[mn],u[mn];
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(vis[y])continue;
        int j=ind[x][i];
        if(!u[x]){
            u[x]=u[y]=1;
            me.push_back(j);
        }
        dfs(y);
    }
    if(!u[x])u[x]=1,is.push_back(x);
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m,i;
        scanf("%d%d",&n,&m);
        for(i=1;i<=3*n;i++)g[i].clear(),ind[i].clear();
        me.clear();
        is.clear();
        memset(vis,0,3*n+1);
        memset(u,0,3*n+1);
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
            ind[a].push_back(i);
            ind[b].push_back(i);
        }
        for(i=1;i<=3*n;i++)if(!vis[i])dfs(i);
        if(is.size()>=n){
            printf("IndSet\n");
            for(i=0;i<n;i++)printf("%d ",is[i]);
        }
        else{
            printf("Matching\n");
            for(i=0;i<n;i++)printf("%d ",me[i]);
        }
        printf("\n");
    }
}