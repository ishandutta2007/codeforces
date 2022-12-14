#include <stdio.h>

int ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a%b!=0)
		{
			printf("-1\n");
			continue;
		}
		if(a==b)
		{
			printf("%d ",a);
			for(int i=2;i<=a-1;i++) printf("%d ",i);
			printf("1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) ans[i] = i;
		ans[a] = 1;
		ans[1] = b;
		ans[b] = a;
		int p = b;
		while(1)
		{
			for(int i=2;p*i<a;i++)
			{
				if(a%(p*i)==0)
				{
					int t = ans[i*p];
					ans[i*p] = ans[p];
					ans[p] = t;
					p*=i;
					goto u;
				}
			}
			break;
			u:;
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}