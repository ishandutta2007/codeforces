#include <stdio.h>
#include <algorithm>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int sum1 = 0;
		for(int i=1;i<=a;i++) sum1 += (x[i]^y[i]);
		
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		
		int sum2 = 1;
		for(int i=1;i<=a;i++) sum2 += (x[i]^y[i])%2;
		printf("%d\n",sum1<sum2?sum1:sum2);
	}
}