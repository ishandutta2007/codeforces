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
		for(int i=0;i<a;i++)
		{
			int b;
			scanf("%d",&b);
			if(i%2==0&&b%2==1) count1++;
			if(i%2==1&&b%2==0) count2++;
		}
		if(count1!=count2) printf("-1\n");
		else printf("%d\n",count1);
	}
}