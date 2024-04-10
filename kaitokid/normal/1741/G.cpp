#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,f,k,h[10009];
vector<int>v[10009];
int z[10009];
int ds[10009][(1<<6)+10];
vector<int>msk[10009];
bool dp[10009][(1<<6)+10];
bool nt[10009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
     cin>>n>>m;
     for(int i=1;i<=n;i++)v[i].clear();
     for(int i=0;i<m;i++)
     {
         int x,y;
         cin>>x>>y;
         v[x].push_back(y);
         v[y].push_back(x);

     }
     cin>>f;
     for(int i=1;i<=f;i++)cin>>h[i];
     int mxx=max(n,f);
     for(int i=0;i<=mxx+1;i++)
     {
      z[i]=0;
      nt[i]=0;
      msk[i].clear();
     }
     cin>>k;
     for(int i=0;i<k;i++)
     {
         int x;
         cin>>x;
         z[h[x]]|=(1<<i);
         nt[x]=true;
     }

     ds[1][0]=0;
     for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<k);j++)ds[i][j]=INT_MAX;
     queue<pair<int,int> >q;
     q.push({1,0});
    while(!q.empty())
    {
        int u=q.front().first,ee=q.front().second;
        q.pop();
        for(int i=0;i<v[u].size();i++)
        {
            int w=v[u][i];
            int rr=ee|z[w];
            if(ds[w][rr]<=ds[u][ee]+1)continue;
            ds[w][rr]=ds[u][ee]+1;
            q.push({w,rr});

        }
    }
    for(int i=2;i<=n;i++)
    {
        int d=INT_MAX;
        for(int j=0;j<(1<<k);j++)d=min(d,ds[i][j]);
        for(int j=0;j<(1<<k);j++)if(ds[i][j]==d)msk[i].push_back(j);
    }

    for(int i=0;i<=f;i++)
        for(int j=0;j<(1<<k);j++)dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<f;i++)
        for(int j=0;j<(1<<k);j++)
       {
           if(dp[i][j]==0)continue;
           dp[i+1][j]=1;
           if(nt[i+1])continue;
           for(auto u:msk[h[i+1]])dp[i+1][j|u]=1;
       }
       int res=0;
       for(int i=0;i<(1<<k);i++)
       {
           if(!dp[f][i])continue;
           int u=0;
           for(int j=0;j<k;j++)if(i&(1<<j))u++;
           res=max(res,u);
       }
       res=k-res;
       cout<<res<<endl;

     }
    return 0;
}