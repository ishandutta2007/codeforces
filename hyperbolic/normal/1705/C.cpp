#include <stdio.h>
#include <vector>
char x[200010];
std::pair<long long int,long long int> P[110];
long long int len[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",x+1);
		for(int i=1;i<=b;i++)
		{
			long long int d,e;
			scanf("%lld%lld",&d,&e);
			P[i] = std::make_pair(d,e);
		}
		len[0] = a;
		for(int i=1;i<=b;i++) len[i] = len[i-1] + (P[i].second-P[i].first+1);
		
		while(c--)
		{
			long long int k;
			scanf("%lld",&k);
			for(int i=b;i>=1;i--)
			{
				if(k>len[i-1])
				{
					k -= len[i-1];
					k += (P[i].first-1);
				}
			}
			printf("%c\n",x[k]);
		}
	}
}