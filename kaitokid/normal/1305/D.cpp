#include <bits/stdc++.h>

using namespace std;
int n,pr[1003][1003],ds[1003][1003];
vector<int>v[1003];
vector<pair<int,pair<int,int> > >ans;
bool vis[1003];
void dfs(int root,int x,int dist,int p)
{
    pr[root][x]=p;
    ds[root][x]=dist;
    for(int i=0;i<v[x].size();i++)if(v[x][i]!=p)dfs(root,v[x][i],dist+1,x);

}
void de(int p,int x)
{
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)if(v[x][i]!=p)de(x,v[x][i]);
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)dfs(i,i,0,0);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
    ans.push_back({ds[i][j],{i,j}});
    sort(ans.begin(),ans.end());
    int i=ans.size()-1;
    while(i>=0)
    {
        int x=ans[i].second.first,y=ans[i].second.second;
        if(vis[x]||vis[y]){i--;continue;}
        cout<<"? "<<x<<" "<<y<<endl;
        fflush(stdout);

        int pp;
        cin>>pp;
       if(x!=pp){while(pr[pp][x]!=pp)x=pr[pp][x];de(pp,x);}
        if(y!=pp){while(pr[pp][y]!=pp)y=pr[pp][y];de(pp,y);}
        i--;
            }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){cout<<"! "<<i<<endl;fflush(stdout);return 0;}

    }
    return 0;
}