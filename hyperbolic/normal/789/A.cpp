#include <stdio.h>
int x[100010];
int main()
{
	int a,b;
	int count = 0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		count+=(x[i]/(2*b));
		x[i]%=(2*b);
	}
	int count1 = 0, count2 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>b) count1++;
		else if(x[i]>0) count2++;
	}
	printf("%d",count+count1+(count2+1)/2);
}