#include <stdio.h>

int x[100010],count[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[x[i]]++;
		
		int max = 0;
		int c = 0;
		for(int i=1;i<=a;i++) max = max>count[i]?max:count[i];
		for(int i=1;i<=a;i++) if(count[i]==max) c++;
		for(int i=1;i<=a;i++)
		{
			if(i*(max-1)+1>a-c+1)
			{
				printf("%d\n",i-2);
				break;
			}
		}
	}
}