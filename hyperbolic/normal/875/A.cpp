#include <stdio.h>
int func(int k)
{
	int s = 0;
	while(k)
	{
		s+=k%10;
		k/=10;
	}
	return s;
}

int count = 0;
int ans[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=(a-100>0?a-100:0);i<=a;i++)
	{
		if(i+func(i)==a)
		{
			count++;
			ans[count] = i;
		}
	}
	printf("%d\n",count);
	for(int i=1;i<=count;i++) printf("%d ",ans[i]);
}