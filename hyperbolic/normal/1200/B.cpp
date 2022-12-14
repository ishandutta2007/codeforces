#include <stdio.h>

int x[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		long long int sum = b;
		for(int i=1;i<a;i++)
		{
			if(x[i+1]>=c)
			{
				if(x[i]>=x[i+1]-c) sum += (x[i] - (x[i+1]-c));
				else if(sum+x[i]>=x[i+1]-c) sum -= (x[i+1]-c - x[i]);
				else
				{
					printf("NO\n");
					goto u;
				}
			}
			else sum += x[i];
		}
		printf("YES\n");
		u:;
	}
}