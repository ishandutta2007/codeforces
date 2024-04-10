#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[3009],n;
vector<int>v[3009];
int mx[3009],pr[3009],lvl[3009];
void df(int x,int lv,int p)
{
    lvl[x]=lv;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==p)continue;
        df(v[x][i],lv+1,x);
    }

}
void dfs(int x,int ds,int p)
{
    int u=lvl[x]-ds;
    //cout<<x<<" "<<u<<" "<<ds<<" "<<lvl[x]<<endl;
    u=max(u,0);
    mx[u]=max(mx[u],ds);
    pr[u]=max(pr[u],lvl[x]);
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==p)continue;
        dfs(v[x][i],ds+1,x);
    }

}
void go(int x)
{
   // cout<<x<<endl;
    for(int i=0;i<=n;i++)pr[i]=mx[i]=INT_MIN;
    dfs(x,0,0);
    for(int i=1;i<=n;i++)pr[i]=max(pr[i-1],pr[i]);
    int u=INT_MIN;
    for(int i=n;i>0;i--)
    {
        u=max(u,mx[i]);
        ans[i]=min(ans[i],max(u+i,pr[i-1]));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){ans[i]=INT_MAX;v[i].clear();}
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        df(1,0,0);
        for(int i=1;i<=n;i++)go(i);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;


    }
    return 0;
}