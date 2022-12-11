#include <bits/stdc++.h>
using namespace std;

const int MAX=100005,MOD=1000000007;

struct barr
{
	int u,l,r,s;
}a[MAX];

int w,yl,yr,Val,dp[MAX];
stack <int> b[MAX*4];

bool cmp(const barr &a,const barr &b)
{
	return a.u<b.u;
}

void update(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		b[o].push(Val);
	else
	{
		int m=l+r>>1;
		if (yl<=m) update(o<<1,l,m);
		if (yr>m) update(o<<1|1,m+1,r);
	}
}

void query(int o,int l,int r)
{
	while (!b[o].empty())
	{
		int x=b[o].top();
		if (a[x].u+a[x].s>=yr)
			break;
		b[o].pop();
	}
	if (!b[o].empty())
		if (Val==-1||a[b[o].top()].u>a[Val].u)
			Val=b[o].top();
	if (l<r)
	{
		int m=l+r>>1;
		if (yl<=m) query(o<<1,l,m);
		else query(o<<1|1,m+1,r);
	}
}

int query(int h,int p)
{
	yl=p;
	yr=h;
	Val=-1;
	query(1,1,w);
	return Val!=-1?dp[Val]:1;
}

int main()
{
	int h,n;
	scanf("%d%d%d",&h,&w,&n);
	for (int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i].u,&a[i].l,&a[i].r,&a[i].s);
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++)
	{
		if (a[i].l==1)
			dp[i]=query(a[i].u,a[i].r+1)*2%MOD;
		else if (a[i].r==w)
			dp[i]=query(a[i].u,a[i].l-1)*2%MOD;
		else
			dp[i]=(query(a[i].u,a[i].l-1)+query(a[i].u,a[i].r+1))%MOD;
		yl=a[i].l;
		yr=a[i].r;
		Val=i;
		update(1,1,w);
	}
	int ans=0;
	for (int i=1;i<=w;i++)
		ans=(ans+query(h+1,i))%MOD;
	printf("%d",ans);
	return 0;
}