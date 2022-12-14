#include <stdio.h>

int x[110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int d;
			scanf("%d",&d);
			int ind;
			for(int k=1;k<=c;k++) if(x[k]==d) ind = k;
			
			ans += ind;
			for(int k=ind-1;k>=1;k--)
			{
				int temp = x[k];
				x[k] = x[k+1];
				x[k+1] = temp;
			}
		}
	}
	printf("%d",ans);
}