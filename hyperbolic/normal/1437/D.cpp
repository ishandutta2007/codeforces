#include <stdio.h>

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
		
		int p = 1;
		int limit = 1;
		int h = 1;
		for(int i=3;i<=a;i++)
		{
			if(x[i]<x[i-1])
			{
				if(p==1)
				{
					h++;
					p = limit;
				}
				else p--;
			}
			else limit++;
		}
		printf("%d\n",h);
	}
}