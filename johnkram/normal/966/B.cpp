#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
struct node
{
	int a,b;
	bool operator<(const node& y)const
	{
		return a<y.a;
	}
}a[MAXN];
int n,m1,m2,i,j,m,k,l,b[MAXN],c[MAXN],d[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].b=i;
	}
	sort(a+1,a+n+1);
	for(i=n;i;i--)b[i]=(m2+a[i].a-1)/a[i].a+i;
	for(c[0]=1<<30,i=1;i<=n;i++)c[i]=min(c[i-1],b[i]);
	for(d[n+1]=1<<30,i=n;i;i--)d[i]=min(d[i+1],b[i]);
	for(i=1;i<=n;i++)
	{
		j=(m1+a[i].a-1)/a[i].a;
		if(i+j-1>n)continue;
		if(d[i+j]<=n+1||c[i-1]<=n+1-j)break;
	}
	if(i>n)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d ",j);
	if(d[i+j]<=n+1)
	{
		for(l=n;l>=i+j;l--)if(b[l]<=n+1)break;
		m=n+1-l;
	}
	else
	{
		for(l=i-1;l;l--)if(b[l]<=n+1-j)break;
		m=n+1-l-j;
	}
	printf("%d\n",m);
	for(k=i;k<i+j;k++)printf("%d ",a[k].b);
	puts("");
	for(k=l;k<i;k++)printf("%d ",a[k].b);
	for(k=max(i+j,l);k<=n;k++)printf("%d ",a[k].b);
	return 0;
}