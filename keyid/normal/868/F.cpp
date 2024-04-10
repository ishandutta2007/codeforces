#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int l=1,r=0,a[MAXN],cnt[MAXN];
LL ret,f[MAXN],g[MAXN];

void add(bool ty,int x)
{
	x=a[x];
	if (ty)
	{
		ret+=cnt[x];
		cnt[x]++;
	}
	else
	{
		cnt[x]--;
		ret-=cnt[x];
	}
}

void query(int pl,int pr)
{
	while (r<pr) add(true,++r);
	while (r>pr) add(false,r--);
	while (l<pl) add(false,l++);
	while (l>pl) add(true,--l);
}

void solve(int pl,int pr,int al,int ar)
{
	if (pl>pr)
		return;
	LL ans=LLONG_MAX;
	int p,m=pl+pr>>1;
	for (int i=al;i<=ar&&i<=m;i++)
	{
		query(i,m);
		if (ret+f[i-1]<ans)
		{
			ans=ret+f[i-1];
			p=i;
		}
	}
	g[m]=ans;
	solve(pl,m-1,al,p);
	solve(m+1,pr,p,ar);
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+cnt[a[i]];
		cnt[a[i]]++;
	}
	for (int i=1;i<=n;i++)
		cnt[i]=0;
	for (int i=2;i<=k;i++)
	{
		solve(1,n,1,n);
		for (int j=1;j<=n;j++)
			f[j]=g[j];
	}
	printf("%lld",f[n]);
	return 0;
}