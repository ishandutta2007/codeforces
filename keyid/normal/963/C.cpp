#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

LL nx[MAXN],ny[MAXN],w[MAXN],h[MAXN],c[MAXN];
vector <LL> cnt[MAXN],pat;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&w[i],&h[i],&c[i]);
		nx[i]=w[i];
		ny[i]=h[i];
	}
	sort(nx,nx+n);
	int ncx=unique(nx,nx+n)-nx;
	sort(ny,ny+n);
	int ncy=unique(ny,ny+n)-ny;
	if ((LL)ncx*ncy>n)
	{
		printf("0");
		return 0;
	}
	for (int i=0;i<ncx;i++)
		cnt[i].resize(ncy);
	pat.resize(ncy);
	for (int i=0;i<n;i++)
	{
		int k=lower_bound(nx,nx+ncx,w[i])-nx;
		cnt[k][lower_bound(ny,ny+ncy,h[i])-ny]+=c[i];
	}
	bool flag=true;
	for (int i=0;i<ncx&&flag;i++)
	{
		LL g=0;
		for (int j=0;j<ncy;j++)
			if (cnt[i][j]==0)
			{
				flag=false;
				break;
			}
		if (!flag)
			break;
		for (int j=0;j<ncy;j++)
			g=__gcd(g,cnt[i][j]);
		if (i==0)
		{
			for (int j=0;j<ncy;j++)
				pat[j]=cnt[i][j]/g;
		}
		else
			for (int j=0;j<ncy;j++)
				if (pat[j]!=cnt[i][j]/g)
				{
					flag=false;
					break;
				}
	}
	if (flag)
	{
		LL mn=LLONG_MAX;
		for (int i=0;i<n;i++)
			mn=min(mn,c[i]);
		LL g=mn;
		for (int i=0;i<n;i++)
			g=__gcd(g,c[i]);
		int ans=0;
		for (LL i=1;i*i<=g;i++)
			if (g%i==0)
			{
				ans++;
				if (g!=i*i)
					ans++;
			}
		printf("%d",ans);
	}
	else
		printf("0");
	return 0;
}