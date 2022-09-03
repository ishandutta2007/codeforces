#include<cstdio>
#include<algorithm>

int a[100];

int main()
{
	int i,n,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	std::sort(a,a+n);
	for(i=n-1;i>=0&&s>=0;i--)s-=2*a[i];
	printf("%d",n-i-1);
}