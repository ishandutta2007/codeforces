#include <stdio.h>
#include <vector>

int x[1010],y[1010];
int count[6];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) count[y[i]]++;
		
		if(count[0]==a || count[1]==a)
		{
			for(int i=1;i<a;i++)
			{
				if(x[i]>x[i+1])
				{
					printf("No\n");
					goto u;
				}
			}
		}
		printf("Yes\n");
		u:;
	}
}