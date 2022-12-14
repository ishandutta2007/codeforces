#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int count1=0, count2=0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b==1) count1++;
			else count2++;
		}
		if(count2%2==0)
		{
			if(count1%2==0) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			if(count1<2) printf("NO\n");
			else if(count1%2==0) printf("YES\n");
			else printf("NO\n");
		}
	}
}