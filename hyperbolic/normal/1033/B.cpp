#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		if(b-c>=2)
		{
			printf("NO\n");
			continue;
		}
		long long int d = b+c;
		for(long long int j=2;j*j<=d;j++)
		{
			if(d%j==0)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}