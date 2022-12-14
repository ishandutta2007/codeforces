#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int count1 = 0 ,count2 = 0, count3 = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b==1) count1++;
			if(b==2) count2++;
			if(b==3) count3++;
		}
		printf("%d\n",count1+count3);
	}
}