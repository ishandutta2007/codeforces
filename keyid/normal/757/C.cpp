#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=100005,MAXM=1000005,BASE[2]={31147,31177},MOD[2]={1000000007,1000000009},M=1000000007;

int pbase[2][MAXN],g[MAXN],num[MAXN],cnt[MAXN],fac[MAXM];
pii h[MAXM];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int j=0;j<2;j++)
	{
		pbase[j][0]=1;
		for (int i=1;i<n;i++)
			pbase[j][i]=(LL)pbase[j][i-1]*BASE[j]%MOD[j];
	}
	for (int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		for (int j=0;j<x;j++)
		{
			scanf("%d",&g[j]);
			num[j]=g[j];
		}
		sort(num,num+x);
		int nc=unique(num,num+x)-num;
		fill(cnt,cnt+nc,0);
		for (int j=0;j<x;j++)
			cnt[lower_bound(num,num+nc,g[j])-num]++;
		for (int j=0;j<nc;j++)
		{
			int v=num[j];
			h[v].fi=(h[v].fi+(LL)cnt[j]*pbase[0][i])%MOD[0];
			h[v].sc=(h[v].sc+(LL)cnt[j]*pbase[1][i])%MOD[1];
		}
	}
	sort(h+1,h+m+1);
	fac[0]=1;
	for (int i=1;i<=m;i++)
		fac[i]=(LL)fac[i-1]*i%M;
	int ans=1;
	for (int i=1;i<=m;)
	{
		int j=i+1;
		while (j<=m&&h[j]==h[i]) j++;
		ans=(LL)ans*fac[j-i]%M;
		i=j;
	}
	printf("%d",ans);
	return 0;
}