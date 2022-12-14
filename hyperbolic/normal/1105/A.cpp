#include <stdio.h>
#include <algorithm>

int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int min = 123456789;
	int t = -1;
	for(int i=1;i<=99;i++)
	{
		int sum = 0;
		for(int j=1;j<=a;j++)
		{
			if(x[j]<=(i-1)) sum += (i-1)-x[j];
			if(x[j]>=(i+1)) sum += x[j]-(i+1);
		}
		if(min>sum)
		{
			min = sum;
			t = i;
		}
	}
	printf("%d %d",t,min);
}