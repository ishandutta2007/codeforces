#include <stdio.h>

char x[500010],y[500010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s%s",x+1,y+1);
	
	long long int sum = 0;
	long long int min = 0, max = 0;
	for(int i=1;i<=a;i++)
	{
		min*=2, max*=2;
		if(x[i]=='b') min++;
		if(y[i]=='b') max++;
		if(max-min+1 >= b)
		{
			printf("%lld",sum + (long long int)b*(a-i+1));
			return 0;
		}
		sum += (max-min+1);
	}
	printf("%lld",sum);
}