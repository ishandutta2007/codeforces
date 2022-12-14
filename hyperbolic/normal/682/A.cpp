#include <stdio.h>

int main()
{
	int a,b,i;
	long long int sum=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		// i + j = 5k
		sum += (b+i%5)/5;
		/*if(i%5==0)
		{
			sum += b/5;
		}
		else
		{
			sum += (b+i%5)/5 + 1;
		}*/
	}
	printf("%I64d",sum);
}