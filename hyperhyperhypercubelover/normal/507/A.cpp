#include<cstdio>
#include<algorithm>

std::pair<int,int> a[111];
int b[111];

int main()
{
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	std::sort(a,a+n);
	for(i=0;i<n&&m>=a[i].first;i++)
	{
		m-=a[i].first;
		b[a[i].second]=1;
	}
	printf("%d\n",i);
    for(i=0;i<n;i++)if(b[i])printf("%d ",i+1);
}