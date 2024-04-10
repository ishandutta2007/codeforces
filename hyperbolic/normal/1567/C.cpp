#include <stdio.h>
#include <vector>

int x[110];
int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=10;i++) x[i] = (a%10),a/=10;
		int sum1 = 0, sum2 = 0;
		for(int i=10;i>=2;i-=2) sum1 *= 10, sum1 += x[i];
		for(int i=9;i>=1;i-=2) sum2 *= 10, sum2 += x[i];
		
		printf("%d\n",(sum1+1)*(sum2+1)-2);
	}
}