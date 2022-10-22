#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],n,p;
bool vis[200009][2];
pair <ll,ll> g[200009];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vis[i][0]=vis[i][1]=0;
            g[i]=make_pair(a[i],i);
        }
        vis[1][0]=vis[n][1]=1;
      sort(g+1,g+n+1);
      for(int i=1;i<=n;i++)
      {
          int w=g[i].second;
          if(a[w]>p)break;
          int l,r;
          l=r=w;
          while(!vis[l][0]&&(a[l-1]%a[w]==0))l--;
          while(!vis[r][1]&&(a[r+1]%a[w]==0))r++;
          ans+=(r-l)*a[w];
          if(l!=r){vis[l][1]=vis[r][0]=1;}
          for(int h=l+1;h<r;h++)vis[h][0]=vis[h][1]=1;


      }

     for(int i=1;i<=n;i++)if(!vis[i][1])ans+=p;
     cout<<ans<<endl;
    }
    return 0;
}