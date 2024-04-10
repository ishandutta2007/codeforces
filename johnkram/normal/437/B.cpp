#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100001;
struct node
{
	int num,sum;
}a[MAXN],ans[MAXN];
bool cmp(node x,node y)
{
	return x.sum>y.sum;
}
int S,n,i,m;
int main()
{
	//freopen("250_b.in","r",stdin);
	//freopen("250_b.out","w",stdout);
	scanf("%d%d",&S,&n);
	for(i=1;i<=n;i++)
	{
		a[i].num=i;
		a[i].sum=(i&(-i));
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n&&S>0;i++)if(S>=a[i].sum)
	{
		S-=a[i].sum;
		ans[++m]=a[i];
	}
	if(S>0)puts("-1");
	else
	{
		printf("%d\n",m);
		for(i=1;i<m;i++)printf("%d ",ans[i].num);
		 printf("%d",ans[i].num);
	}
	return 0;
}