#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=1000005;
const LL INF=0x3f3f3f3f3f3f3f3f;

struct ele
{
	LL a;
	int e;
}v[MAXN];

LL K,fac[11],gf[11],dp[1<<11];
int cnt,mn[1<<11][11],now[1<<11],id[1<<11][11],T,vis[1<<11];
map <LL,int> ms;

bool cmp(const ele &x,const ele &y)
{
	return x.e<y.e;
}

void dfs(int cur,int sta,LL d,int id)
{
	if (now[sta]<cnt)
		mn[sta][now[sta]++]=id;
	for (int i=cur;i<cnt;i++)
		if (d*gf[i]<=K)
			dfs(i+1,sta|(1<<i),d*gf[i],id);
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n;
	LL g=0;
	scanf("%d%lld",&n,&K);
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&v[i].a);
		g=__gcd(g,v[i].a);
	}
	for (int i=0;i<n;i++)
		scanf("%d",&v[i].e);
	if (g==1)
	{
		printf("0");
		return 0;
	}
	for (int i=2;(LL)i*i<=g;i++)
		if (g%i==0)
		{
			fac[cnt++]=i;
			do g/=i; while (g%i==0);
		}
	if (g>1)
		fac[cnt++]=g;
	for (int i=0;i<n;i++)
	{
		LL t=1;
		for (int j=0;j<cnt;j++)
			while (v[i].a%fac[j]==0)
			{
				v[i].a/=fac[j];
				t*=fac[j];
			}
		v[i].a=t;
	}
	sort(v,v+n,cmp);
	for (int i=0;i<n;i++)
	{
		if (ms[v[i].a]>=cnt)
			continue;
		++ms[v[i].a];
		for (int k=0;k<cnt;k++)
		{
			gf[k]=1;
			while (v[i].a%fac[k]==0)
			{
				v[i].a/=fac[k];
				gf[k]*=fac[k];
			}
		}
		dfs(0,0,1,i);
	}
	LL ans=INF;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=0;i<cnt;i++)
	{
		for (int j=(1<<cnt)-1;j;j--)
		{
			dp[j]=INF;
			for (int k=j;k;k=(k-1)&j)
			{
				T++;
				for (int l=0;l<i;l++)
					vis[id[k^j][l]]=T;
				for (int l=0;l<now[k];l++)
					if (vis[mn[k][l]]!=T)
					{
						if (dp[k^j]+v[mn[k][l]].e<dp[j])
						{
							dp[j]=dp[k^j]+v[mn[k][l]].e;
							for (int u=0;u<i;u++)
								id[j][u]=id[k^j][u];
							id[j][i]=mn[k][l];
						}
						break;
					}
			}
		}
		if (dp[(1<<cnt)-1]<INF)
			ans=min(ans,(i+1)*dp[(1<<cnt)-1]);
	}
	if (ans<INF)
		printf("%lld",ans);
	else
		printf("-1");
	return 0;
}