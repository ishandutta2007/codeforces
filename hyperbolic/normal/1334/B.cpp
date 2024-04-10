#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		long long int sum = 0;
		for(int i=a;i>=1;i--)
		{
			sum += x[i];
			if(sum < (long long int)(a-i+1)*b)
			{
				printf("%d\n",(a-i));
				goto u;
			}
		}
		printf("%d\n",a);
		u:;
	}
}