#include<cstdio>
#include<algorithm>

int a[111111];

int main()
{
	int i,n,r=0,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(i=0;i<n;i++)if(t<=a[i])
	{
		r++;
		t+=a[i];
	}
	printf("%d",r);
}