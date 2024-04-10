#include <stdio.h>
#include <vector>

std::vector<long long int> V[100010];
long long int value[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++)
		{
			V[i].push_back(0);
			for(int j=1;j<=b;j++)
			{
				int c;
				scanf("%d",&c);
				V[i].push_back(c);
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			long long int sum = 0;
			for(int j=1;j<=b;j++) sum += V[i][j]*j;
			value[i] = sum;
		}
		
		int ans1;
		long long int ans2;
		for(int i=1;i<a;i++)
		{
			if(value[i]!=value[i+1])
			{
				int s1 = 0, s2 = 0;
				for(int j=1;j<=a;j++) if(value[j]==value[i]) s1++;
				for(int j=1;j<=a;j++) if(value[j]==value[i+1]) s2++;
				if(s1==1) ans1 = i;
				else ans1 = i+1;
			}
		}
		if(ans1==1) ans2 = value[ans1] - value[2];
		else ans2 = value[ans1] - value[1];
		printf("%d %lld\n",ans1,ans2);
	}
}