#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int last = 0;
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<a;j++)
			{
				if(x[j]<x[j+1])
				{
					last = j;
					x[j]++;
					goto u;
				}
			}
			printf("-1\n");
			goto v;
			u:;
		}
		printf("%d\n",last);
		v:;
	}
}