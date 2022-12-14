#include <stdio.h>

int x[100010];
int left[100010],right[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	left[1] = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i]>=left[i-1]+1) left[i] = left[i-1]+1;
		else left[i] = x[i];
	}
	right[a] = 1;
	for(int i=a-1;i>=1;i--)
	{
		if(x[i]>=right[i+1]+1) right[i] = right[i+1]+1;
		else right[i] = x[i];
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c = (left[i]<right[i]?left[i]:right[i]);
		ans = ans>c?ans:c;
	}
	printf("%d",ans);
}