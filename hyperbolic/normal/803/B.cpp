#include <stdio.h>

int x[200010],left[200010],right[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0) p = i;
		left[i] = p;
	}
	p = a+1;
	for(int i=a;i>=1;i--)
	{
		if(x[i]==0) p = i;
		right[i] = p;
	}
	
	for(int i=1;i<=a;i++)
	{
		int l = 12345678,r = 12345678;
		if(left[i]>=1) l = i-left[i];
		if(right[i]<=a) r = right[i]-i;
		printf("%d ",l<r?l:r);
	}
}