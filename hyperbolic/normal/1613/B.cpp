#include <stdio.h>
#include <algorithm>

int x[200010];
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
		
		int C = 0;
		for(int i=2;i<=a;i++)
		{
			if(C>=(a/2)) break;
			printf("%d %d\n",x[i],x[1]);
			C++;
		}
	}
}