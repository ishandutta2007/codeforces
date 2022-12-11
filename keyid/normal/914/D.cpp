#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=500005,MAXQ=400005;

int a[MAXN],yl,yr,V,gv[MAXN*4];

void build(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		build(lc,l,m);
		build(rc,m+1,r);
		gv[o]=__gcd(gv[lc],gv[rc]);
	}
	else
		gv[o]=a[l];
}

void update(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yl<=m) update(lc,l,m);
		else update(rc,m+1,r);
		gv[o]=__gcd(gv[lc],gv[rc]);
	}
	else
		gv[o]=V;
}

int cnt;

bool query2(int o,int l,int r)
{
	if (gv[o]%V==0)
		return true;
	if (l==r)
		return ++cnt<2;
	int m=l+r>>1;
	if (!query2(o<<1,l,m))
		return false;
	if (!query2(o<<1|1,m+1,r))
		return false;
	return true;
}

bool query(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		if (!query2(o,l,r))
			return false;
	}
	else
	{
		int m=l+r>>1;
		if (yl<=m&&!query(o<<1,l,m))
			return false;
		if (yr>m&&!query(o<<1|1,m+1,r))
			return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int ty;
		scanf("%d",&ty);
		if (ty==1)
		{
			scanf("%d%d%d",&yl,&yr,&V);
			cnt=0;
			puts(query(1,1,n)?"YES":"NO");
		}
		else
		{
			scanf("%d%d",&yl,&V);
			update(1,1,n);
		}
	}
	return 0;
}