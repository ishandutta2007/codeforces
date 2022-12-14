#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int count1 = 0, count2 = 0;
		while(a%2==0) a/=2,count1++;
		while(a%3==0) a/=3,count2++;
		if(a>1) printf("-1\n");
		else if(count1>count2) printf("-1\n");
		else printf("%d\n",count2+(count2-count1));
	}
}