#include <stdio.h>

int x[5010];
long long int count[5010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[i] = 0;
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			while(count[i]>0)
			{
				if(x[i]==1)
				{
					count[i+1] += count[i];
					count[i] = 0;
					break;
				}
				else
				{
					if(i+x[i]<=a) count[i+x[i]]++;
					x[i]--;
					count[i]--;
				}
			}
			
			if(x[i]>a-i)
			{
				ans += (x[i]-(a-i));
				x[i] = a-i;
			}
			for(int j=i+x[i];j>=i+2;j--) count[j]++;
			ans += (x[i]-1);
			x[i] = 1;
		}
		printf("%lld\n",ans);
	}
}