#include <stdio.h>

int x[10010],min[10010],max[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		max[1] = x[1];
		for(int i=2;i<=a;i++) max[i] = max[i-1]>x[i]?max[i-1]:x[i];
		min[a] = x[a];
		for(int i=a-1;i>=1;i--) min[i] = min[i+1]<x[i]?min[i+1]:x[i];
		
		for(int i=1;i<a;i++)
		{
			if(max[i]>min[i+1])
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}