#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20000009];
int dv[20000009];
int pr[20000009];
vector<pair<int,int > > g;
void go(int x,int z)
{
    if(x==g.size()){dv[z]++;return ;}
    go(x+1,z);
    for(int i=0;i<g[x].second;i++)
    {
        z*=g[x].first;
        go(x+1,z);
    }

}
int main() {
	int n,x,mx=20000000;

	scanf("%d",&n);

	vector<int>p;
   for(int i=2;i<=mx;i++)
   {
       if(pr[i])continue;
       p.push_back(i);
       pr[i]=i;
       for(int j=2*i;j<=mx;j+=i)pr[j]=i;
   }
   for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        g.clear();
        while(x>1)
        {
            int u=pr[x],d=0;
            while(x%u==0){x/=u;d++;}
            g.push_back({u,d});
        }
      go(0,1);
    }
   dp[1]=n;
   ll ans=n;
   for(int i=1;i<=mx;i++)
   for(int j=0;(j<p.size()&& i*1LL*p[j]<=mx) ;j++)
   {
       int u=i*p[j];
        dp[u]=max(dp[u],dp[i]+dv[u]*1LL*(u-i));
   }
   for(int i=1;i<=mx;i++)ans=max(ans,dp[i]);
   printf("%lld",ans);

	return 0;
}