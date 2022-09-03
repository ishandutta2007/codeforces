#include<cstdio>

int main()
{
	int i,n,ans=1;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		ans+=i*12;
	}
	printf("%d",ans);
}