#include<cstdio>
#include<algorithm>

int a[3333];

int main()
{
	int i,n,t=0,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(i=0;i<n;i++)
	{
		t=std::max(a[i],t+1);
        r+=t-a[i];
	}
	printf("%d",r);
}