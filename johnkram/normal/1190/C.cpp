#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
struct node
{
	int l0,r0,l1,r1;
	node operator+(const node& y)const
	{
		node t;
		t.l0=min(l0,y.l0);
		t.l1=min(l1,y.l1);
		t.r0=max(r0,y.r0);
		t.r1=max(r1,y.r1);
		return t;
	}
}a[MAXN],s[MAXN],t[MAXN],d;
int n,m,i;
char c[MAXN];
int main()
{
	scanf("%d%d%s",&n,&m,c+1);
	a[0].l0=a[0].l1=n+1;
	a[0].r0=a[0].r1=0;
	for(i=1;i<=n;i++)if(c[i]=='0')
	{
		a[i].l0=a[i].r0=i;
		a[i].l1=n+1;
		a[i].r1=0;
	}
	else
	{
		a[i].l1=a[i].r1=i;
		a[i].l0=n+1;
		a[i].r0=0;
	}
	for(s[0]=a[0],i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(s[n].r1-s[n].l1+1<=m||s[n].r0-s[n].l0+1<=m)
	{
		puts("tokitsukaze");
		return 0;
	}
	for(t[n+1]=a[0],i=n;i;i--)t[i]=t[i+1]+a[i];
	for(i=1;i+m-1<=n;i++)
	{
		d.l0=i;
		d.r0=i+m-1;
		d.l1=n+1;
		d.r1=0;
		d=s[i-1]+d+t[i+m];
		if(d.r1-d.l1+1>m&&d.r0-d.l0+1>m)
		{
			puts("once again");
			return 0;
		}
		d.l1=i;
		d.r1=i+m-1;
		d.l0=n+1;
		d.r0=0;
		d=s[i-1]+d+t[i+m];
		if(d.r1-d.l1+1>m&&d.r0-d.l0+1>m)
		{
			puts("once again");
			return 0;
		}
	}
	puts("quailty");
	return 0;
}