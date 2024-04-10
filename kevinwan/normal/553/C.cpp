#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
vector<int>g[mn],l[mn];
bool vis[mn],fail=0,val[mn];
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        int t=l[x][i];
        if(vis[y]){
            if(val[x]^t^val[y])fail=1;
        }
        else{
            val[y]=val[x]^t;
            dfs(y);
        }
    }
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        g[b].push_back(a);
        l[a].push_back(c^1);
        l[b].push_back(c^1);
    }
    ll ans=mod/2+1;
    for(i=1;i<=n;i++)if(!vis[i])dfs(i),ans=ans*2%mod;
    if(fail)printf("0");
    else printf("%lld",ans);
}