#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int n,m,M,i,j,n0,n1,a[MAXN],h[MAXN],ne[MAXN*MAXN],p[MAXN*MAXN],L[MAXN];
bool b[MAXN];
void add(int u,int v)
{
	p[++M]=v;
	ne[M]=h[u];
	h[u]=M;
}
bool work(int now)
{
	for(int i=h[now];i;i=ne[i])if(!b[p[i]])
	{
		b[p[i]]=1;
		if(!L[p[i]]||work(L[p[i]]))
		{
			L[p[i]]=now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(a[n]*2>=m)
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<n&&a[i+1]*3<=m;i++);
	n0=n-i;
	n1=i;
	if(n0>n1)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n0;i++)for(j=1;j<=n1;j++)if(a[i+n1]%a[j]==0&&a[i+n1]*2+a[j]<=m)add(i,j);
	for(i=1;i<=n0;i++)
	{
		memset(b,0,sizeof(b));
		if(!work(i))
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",n1);
	for(i=1;i<=n1;i++)if(L[i])printf("%d %d\n",a[L[i]+n1]*2+a[i],a[L[i]+n1]+a[i]);
	else printf("%d %d\n",a[i]*3,a[i]*2);
	return 0;
}