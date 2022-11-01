#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=3e5,MOD=1e9+7;
vector<int>G[maxn];
int n,h[maxn];
ll a[maxn],ans,t0[maxn],t1[maxn];

void dfs(int v,int par)
{
  t0[v]=1;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(u==par) continue;

      h[u]=1-h[v];
      dfs(u,v);
      t0[v]+=t1[u];
      t1[v]+=t0[u];
    }
  int sum=t0[v]+t1[v];
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(u==par) continue;

      ans=(ans+a[v]*t1[u]%MOD*(sum-t0[u]-t1[u]-1)%MOD)%MOD;
      ans=(ans+MOD-a[v]*t0[u]%MOD*(sum-t0[u]-t1[u]-1)%MOD)%MOD;
    }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<n;i++)
    {
      int v,u;
      cin>>v>>u;
      G[v].push_back(u);
      G[u].push_back(v);
    }
  dfs(1,0);
  // cerr<<ans<<endl;
  for(int i=1;i<=n;i++)
    {
      int sum=t0[i]+t1[i];
      ans=(ans+a[i]*t0[i]%MOD*(n-sum+1)%MOD)%MOD;
      ans=(ans+MOD-a[i]*t1[i]%MOD*(n-sum+1)%MOD)%MOD;
      //cerr<<ans<<" ";
      if(h[i]) {
	ans=(ans+a[i]*(t1[1]-t0[i]+1)%MOD*sum%MOD)%MOD;
	ans=(ans+MOD-a[i]*(t0[1]-t1[i])%MOD*sum%MOD)%MOD;
      }
      else {
	ans=(ans+a[i]*(t0[1]-t0[i]+1)%MOD*sum%MOD)%MOD;
	ans=(ans+MOD-a[i]*(t1[1]-t1[i])%MOD*sum%MOD)%MOD;
      }
      // cerr<<ans<<" ";
      ans=(ans+MOD-a[i])%MOD;
      // cerr<<i<<" "<<ans<<endl;
    }
  cout<<ans<<endl;
}