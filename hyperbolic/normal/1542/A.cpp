#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int count1 = 0 ,count2 = 0;
		for(int i=1;i<=2*a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b%2==1) count1++;
			else count2++;
		}
		if(count1==count2) printf("Yes\n");
		else printf("No\n");
	}
}