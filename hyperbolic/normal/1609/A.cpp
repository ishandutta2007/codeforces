#include <stdio.h>
#include <algorithm>

long long int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		int C = 0;
		for(int i=1;i<=a;i++) while(x[i]%2==0) C++, x[i]/=2;
		std::sort(x+1,x+a+1);
		for(int i=1;i<=C;i++) x[a]*=2;
		
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		printf("%lld\n",sum);
	}
}