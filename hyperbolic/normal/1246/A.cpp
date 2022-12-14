#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=1000;i++)
	{
		int s = a-b*i;
		if(s<0) continue;
		int count = 0;
		while(s)
		{
			if(s%2==1) count++;
			s/=2;
		}
		if(count<=i&&i<=a-b*i)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
}