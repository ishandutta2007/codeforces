#include <stdio.h>

int sum[1100010];
int x[300010];
int C;
int update(int k)
{
	k+=C;
	while(k)
	{
		sum[k]++;
		k/=2;
	}
}
int getSum(int a, int b)
{
	int s = 0;
	a+=C,b+=C;
	while(a<b)
	{
		if(a%2==1)
		{
			s+=sum[a];
			a++;
		}
		if(b%2==0)
		{
			s+=sum[b];
			b--;
		}
		a/=2,b/=2;
	}
	if(a==b) s+=sum[a];
	return s;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(C=1;C<a;C*=2);
	C--;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("1 ");
	for(int i=1;i<=a;i++)
	{
		update(x[i]);
		int s = 0;
		int min = 1, max = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(getSum(h,a)==a-h+1)
			{
				s = a-h+1;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d ",i-s+1);
	}
}