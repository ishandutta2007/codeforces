#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%4==2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=a/2;i++) printf("%d ",2*i);
		for(int i=a/2+1;i<a;i++) printf("%d ",2*i-a-1);
		printf("%d\n",a+a/2-1);
	}
}