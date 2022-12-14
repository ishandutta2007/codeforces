#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	int s =1, t = 2, k = 3;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==s)
		{
			int u = t;
			t = k;
			k = u;
		}
		else if(b==t)
		{
			int u = s;
			s = k;
			k = u;
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}