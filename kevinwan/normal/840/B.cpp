#include <bits/stdc++.h>
using namespace std;
const int mn=3e5+10;
int d[mn];
bool vis[mn];
vector<int> g[mn],in[mn],u;
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(vis[y])continue;
        dfs(y);
        if(d[y]==1){
            d[x]^=1;
            u.push_back(in[x][i]);
        }
    }
}
int main()
{
    int n,m,i,a,b;
    scanf("%d%d",&n,&m);
    int st=1;
    for(i=1;i<=n;i++){
        scanf("%d",d+i);
        if(d[i]<0)st=i;
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        in[a].push_back(i+1);
        in[b].push_back(i+1);
    }
    dfs(st);
    if(d[st]==1)printf("-1");
    else{
        printf("%d\n",u.size());
        for(int x:u)printf("%d\n",x);
    }
}