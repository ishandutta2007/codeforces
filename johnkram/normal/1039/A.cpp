#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,i,x[MAXN],c[MAXN],d[MAXN];
ll m,l,a[MAXN],b[MAXN];
int main()
{
	scanf("%d%I64d",&n,&m);
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	for(i=1;i<=n;i++)
	{
		scanf("%d",x+i);
		if(x[i]<x[i-1]||x[i]<i)
		{
			puts("No");
			return 0;
		}
		c[i]++;
		c[x[i]]--;
		d[x[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		c[i]+=c[i-1];
		l=max(b[i-1]+1,a[i]+m);
		if(c[i])l=max(l,a[i+1]+m);
		if(d[i]&&i<n&&l>=a[i+1]+m)
		{
			puts("No");
			return 0;
		}
		b[i]=l;
	}
	puts("Yes");
	for(i=1;i<=n;i++)printf("%I64d ",b[i]);
	return 0;
}