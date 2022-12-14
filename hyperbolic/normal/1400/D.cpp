#include <stdio.h>

int count1[3010][3010];
int x[3010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) count1[i][j] = 0;
		
		long long int ans = 0;
		long long int sum = 0;
		for(int i=3;i<=a-1;i++)
		{
			for(int j=1;j<=i-2;j++) count1[x[j]][x[i-1]]++;
			
			long long int sum = 0;
			for(int j=i+1;j<=a;j++) sum += count1[x[i]][x[j]];
			
			ans += sum;
		}
		printf("%lld\n",ans);
	}
}