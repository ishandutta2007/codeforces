#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]<=i)
			{
				printf("%d\n",i+1);
				goto u;
			}
		}
		
		printf("%d\n",1);
		u:;
	}
}