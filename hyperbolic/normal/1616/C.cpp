#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(a<=2)
		{
			printf("0\n");
			continue;
		}
		
		int ans = a;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				int gap1 = (x[j]-x[i]);
				int gap2 = (j-i);
				
				int s = 0;
				for(int k=1;k<=a;k++)
				{
					if((j-i)*x[k] != (j-i)*x[i]+(x[j]-x[i])*(k-i)) s++;
				}
				ans = ans<s?ans:s;
			}
		}
		printf("%d\n",ans);
	}
}