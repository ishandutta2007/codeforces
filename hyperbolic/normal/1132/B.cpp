#include <stdio.h>
#include <algorithm>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c;
		scanf("%d",&c);
		printf("%lld\n",sum-x[a-c+1]);
	}
}