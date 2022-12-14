#include <stdio.h>
#include <algorithm>

std::pair<long long int, long long int> x[7010];
long long int S[7010];
int check[7010];
int count[7010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i].first);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i].second);
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if((x[i].first&x[j].first)==x[i].first) count[i]++;
	
	long long int ans = 0;
	while(1)
	{
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				if(count[i]==1)
				{
					check[i] = 1;
					for(int j=1;j<=a;j++) if((x[i].first&x[j].first)==x[j].first) count[j]--;
					goto u;
				}
			}
		}
		for(int i=1;i<=a;i++) if(check[i]==0) ans += x[i].second;
		break;
		u:;
	}
	
	printf("%lld",ans);
}