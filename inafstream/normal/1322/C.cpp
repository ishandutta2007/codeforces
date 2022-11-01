#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int t,n,m,i,j,fa[500005];
vector<int> adj[500005];
long long val[500005],sum[500005],ans;
int e[2]={1000003,1000033},mod[2]={1000000007,1000000009};
map<pair<int,int>,int> fir;

int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		rep(i,n) adj[i].clear();
		fir.clear();
		
		rep(i,n)
		{
			fa[i]=i;
			sum[i]=0;
			scanf("%I64d",&val[i]);
		}
		rep(i,m)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			adj[y].push_back(x); 
		}
		rep(i,n)
		{
			sort(adj[i].begin(),adj[i].end());
			int h0=adj[i].size(),h1=adj[i].size();
			for (j=0;j<adj[i].size();j++)
			{
				h0=(1ll*h0*e[0]+adj[i][j])%mod[0];
				h1=(1ll*h1*e[1]+adj[i][j])%mod[1];
			}
			
			pair<int,int> tmp=make_pair(h0,h1);
			if (fir.count(tmp)) fa[fnd(i)]=fnd(fir[tmp]); else fir[tmp]=i;
		}
		
		rep(i,n) if (!adj[i].empty())
		{
			sum[fnd(i)]+=val[i];
		}
		ans=0;
		rep(i,n) if (!adj[i].empty()&&fa[i]==i)
		{
			ans=__gcd(ans,sum[fnd(i)]);
		}
		
		printf("%I64d\n",ans);
	}
	return 0;
}