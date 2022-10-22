#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d[1009];
bool vis[1009];
int pr[1009];
int p(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=p(pr[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int t;
     cin>>t;
    while(t--)
  {
      int n;
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          cin>>d[i];
          pr[i]=i;
          vis[i]=false;
      }

      int mx=0,g=-1;
      for(int i=1;i<=n;i++)
      {
          if(vis[i])continue;
          if(d[i]>mx){mx=d[i];g=i;}
      }
      while(g!=-1)
      {
          vis[g]=true;
          for(int i=0;i<d[g];i++)
          {
              cout<<"? "<<g<<endl;
              fflush(stdout);
              int u;
              cin>>u;
              if(vis[u])
              {
                  pr[p(g)]=p(u);
                  break;
              }
              vis[u]=true;
              pr[p(u)]=p(g);

          }
          mx=0,g=-1;
      for(int i=1;i<=n;i++)
      {
          if(vis[i])continue;
          if(d[i]>mx){mx=d[i];g=i;}
      }

      }

      cout<<"! ";
      for(int i=1;i<=n;i++)cout<<p(i)<<" ";
      cout<<endl;
      fflush(stdout);
  }

    return 0;
}