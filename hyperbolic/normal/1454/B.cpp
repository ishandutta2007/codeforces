#include <stdio.h>

int count[200010],x[200010];
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
		
		int p = -1;
		for(int i=1;i<=a;i++)
		{
			if(count[i]==1)
			{
				p = i;
				goto u;
			}
		}
		printf("-1\n");
		continue;
		
		u:;
		for(int i=1;i<=a;i++) if(x[i]==p) printf("%d\n",i);
	}
}