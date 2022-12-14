#include <stdio.h>

int x[200010];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++)
		{
			if(abs(x[i]-x[i+1])>=2)
			{
				printf("YES\n");
				printf("%d %d\n",i,i+1);
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}