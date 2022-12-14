#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			printf("1 1\n");
			continue;
		}
		
		int p = 0,t = 0;
		for(int i=1;;i++)
		{
			if(i*i>=a)
			{
				t = (i-1)*(i-1);
				p = i;
				break;
			}
		}
		
		if(t+p>=a) printf("%d %d\n",a-t,p);
		else printf("%d %d\n",p,p-(a-t-p));
	}
}