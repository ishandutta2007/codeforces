#include <stdio.h>

int x[50][50];
int count[6];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		int ans = 0;
		for(int k=2;k<=(a+b+2)/2;k++)
		{
			if(k==a+b+2-k) break;
			//k2 = a+b+2-k;
			count[0] = count[1] = 0;
			for(int i=1;i<=a;i++)
			{
				int j = k-i;
				if(j<1 || j>b) continue;
				count[x[i][j]]++;
			}
			
			for(int i=1;i<=a;i++)
			{
				int j = a+b+2-k-i;
				if(j<1 || j>b) continue;
				count[x[i][j]]++;
			}
			
			ans += (count[0]<count[1]?count[0]:count[1]);
		}
		printf("%d\n",ans);
	}
}