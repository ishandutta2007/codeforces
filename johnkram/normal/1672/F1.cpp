#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,m,i,j,a[MAXN],s[MAXN],h[MAXN],ne[MAXN],b[MAXN],c[MAXN];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fill(s+1,s+n+1,0);
		fill(h+1,h+n+1,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			ne[i]=h[++s[a[i]]];
			h[s[a[i]]]=i;
		}
		for(i=1;i<=n;i++)
		{
			for(j=h[i],m=0;j;j=ne[j])b[++m]=j;
			sort(b+1,b+m+1,cmp);
			for(j=1;j<=m;j++)c[b[j]]=a[b[j%m+1]];
		}
		for(i=1;i<=n;i++)printf("%d%c",c[i],i==n?'\n':' ');
	}
	return 0;
}