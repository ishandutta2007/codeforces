#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	long long int ans = 0;
	int max = 0;
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		int min = b<c?b:c;
		if(b==c)
		{
			if(min>=max) ans += (min-max+1);
			max = (b+1);
		}
		else
		{
			if(min>=max) ans += (min-max+1);
			max = (b>c?b:c);
		}
	}
	
	printf("%lld",ans);
}