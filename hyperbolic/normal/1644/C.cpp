#include <stdio.h>
#define MIN -1234567890

int x[5010],check[5010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) check[i] = MIN;
		for(int i=1;i<=a;i++)
		{
			int S = 0;
			for(int j=i;j<=a;j++)
			{
				S += x[j];
				check[j-i+1] = check[j-i+1]>S?check[j-i+1]:S;
			}
		}
		
		int ans = 0;
		for(int i=a-1;i>=1;i--) check[i] = check[i]>check[i+1]?check[i]:check[i+1];
		
		for(int i=1;i<=a;i++) ans = ans>check[i]?ans:check[i];
		for(int i=1;i<=a;i++) if(b>0) check[i] += b*i;
		
		for(int i=0;i<=a;i++)
		{
			ans = ans>check[i]?ans:check[i];
			printf("%d ",ans);
		}
		printf("\n");
		
	}
}