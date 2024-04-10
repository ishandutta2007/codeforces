#include <stdio.h>

int check[2010][2010],x[2010][2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
		
		for(int k=2;k<=2*a;k+=4)
		{
			int s = 1, t = k-s;
			while(t>a) t--,s++;
			while(t>=1&&s<=a)
			{
				check[s][t] = 1;
				s+=2,t-=2;
			}
		}
		
		for(int k=2;k<=2*a;k+=4)
		{
			int s = 1, t = k-s;
			while(t>a) t--,s++;
			while(t>=1&&s<=a)
			{
				check[a-s+1][t] = 1;
				s+=2,t-=2;
			}
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(check[i][j]==1) ans^=x[i][j];
		printf("%lld\n",ans);
	}
}