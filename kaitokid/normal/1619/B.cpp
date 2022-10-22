#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>vis;
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
        vis.clear();
        int ans=0;
        for(int i=1;i*i<=n;i++)
        {
            ans++;
            vis[i*i]=true;

        }
      for(int i=1;i*i*i<=n;i++)
      {
          if(vis[i*i*i])continue;
          ans++;
          vis[i*i*i]=true;
      }
      cout<<ans<<endl;
    }

    return 0;
}