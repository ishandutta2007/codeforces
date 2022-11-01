#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,len[200005],seq[200005],son[200005];
vector<int> g[200005];

void dfs1(int x,int p)
{
	for(int y:g[x])if(y!=p)
	{
		dfs1(y,x);
		if(son[x]==0||len[y]>len[son[x]])
		{
			son[x]=y;
		}
	}
	len[x]=len[son[x]]+1;
}

void dfs2(int x,int p)
{
	if(son[x]) len[son[x]]=len[x],seq[x]=0; else seq[x]=len[x];
	for(int y:g[x])if(y!=p) dfs2(y,x);
}

void solve()
{
	long long ans=-0x7fffffffffffffffll;
	int i;
	scanf("%d%d",&n,&m);
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs1(1,0);
	dfs2(1,0);
	
	sort(seq+1,seq+n+1);
	reverse(seq+1,seq+n+1);
	
	int cntb=n;
	for(i=0;i<=m;i++)
	{
		cntb-=seq[i];
		int t=min(n/2,cntb);
		long long tmp=1ll*(i-t)*(n-i-t);
		if(t+1<=cntb)
		{
			t++;
			tmp=min(tmp,1ll*(i-t)*(n-i-t));
		}
		ans=max(ans,tmp);
	}
	
	printf("%lld\n",ans);
}

int main()
{
	int t=1;
//	scanf("%d",&t);
	while(t--) solve();
	return 0;
}