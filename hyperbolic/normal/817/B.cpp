#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	if(x[3]==x[2])
	{
		if(x[2]==x[1])
		{
			int count = 0;
			for(int i=1;i<=a;i++) if(x[i]==x[1]) count++;
			printf("%lld",(long long int)count*(count-1)*(count-2)/6);
		}
		else
		{
			int count = 0;
			for(int i=2;i<=a;i++) if(x[i]==x[2]) count++;
			printf("%lld",(long long int)count*(count-1)/2);
		}
	}
	else
	{
		int count = 0;
		for(int i=3;i<=a;i++) if(x[i]==x[3]) count++;
		printf("%lld",(long long int)count);
	}
}