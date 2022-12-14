#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int sum = a+b+c;
		if(sum%9!=0) printf("NO\n");
		else
		{
			int h = sum/9;
			if(h<=a && h<=b && h<=c) printf("YES\n");
			else printf("NO\n");
		}
	}
}