#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ed[100009];
int deg[100009],lv[100009],pr[100009],d[100009];
bool rs[100009],vis[100009];
int go(int x,int lvl)
{
    lv[x]=lvl;
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(u==pr[x])continue;
        pr[u]=x;
        go(u,lvl+1);
    }
}
bool bl(int x,int y)
{
    return make_pair(-lv[x],x)<make_pair(-lv[y],y);
}
bool ct(int x,int y)
{
    if(x==pr[y])return rs[y];
    return rs[x];
}
int dfs(int x,int p)
{
    vis[x]=true;
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(u==p)continue;
        if(ct(x,u))continue;
        return dfs(u,x);
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{int n;
cin>>n;
for(int i=1;i<=n;i++){ed[i].clear();deg[i]=0;d[i]=i;rs[i]=vis[i]=false;}
for(int i=1;i<n;i++)
{
    int x,y;
    cin>>x>>y;
    deg[x]++;
    deg[y]++;
    ed[x].push_back(y);
    ed[y].push_back(x);

}
go(1,0);
sort(d+1,d+n+1,bl);
vector<pair<int,int> > ans;
for(int i=1;i<=n;i++)
{
    int u=d[i];
    if(deg[u]<=2)continue;
    if(u!=1){ans.push_back({pr[u],u});deg[u]--;deg[pr[u]]--;rs[u]=true;}
    for(int q=0;q<ed[u].size();q++)
    {
        if(deg[u]<=2)break;
        int z=ed[u][q];
        if(z==pr[u])continue;
        if(rs[z])continue;
        ans.push_back({z,u});
        deg[z]--;
        deg[u]--;
        rs[z]=true;
    }
}
vector<pair<int,int> >g;
for(int i=1;i<=n;i++)
{
    if(vis[i]||(deg[i]>1))continue;
    g.push_back({i,dfs(i,0)});
}
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++)
    cout<<ans[i].second<<" "<<ans[i].first<<" "<<g[i].second<<" "<<g[i+1].first<<endl;

}

    return 0;
}