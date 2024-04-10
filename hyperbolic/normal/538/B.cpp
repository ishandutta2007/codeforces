#include <stdio.h>
int x[110],y[110];
int main()
{
	int a,count=1,b,i,j;
	scanf("%d",&a);
	while(a)
	{
		x[count++] = a%10;
		a/=10;
	}
	count--;
	for(i=1;i<=9;i++)
	{
		b=1;
		for(j=1;j<=count;j++)
		{
			if(x[j]>0)
			{
				y[i]+=b;
				x[j]--;
			}
			b*=10;
		}
	}
	for(i=1;i<=9;i++)
	{
		if(y[i]==0) break;
	}
	i--;
	printf("%d\n",i);
	for(j=1;j<=i;j++) printf("%d ",y[j]);
}