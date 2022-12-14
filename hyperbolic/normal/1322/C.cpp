#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 99999971
std::vector<int> V[500010];
long long int sum[500010];
long long int z[500010];
bool cmp(int a, int b)
{
	return z[a]<z[b];
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int x[500010];
int y[500010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[d].push_back(c);
		}
		for(int i=1;i<=a;i++) if(V[i].size()>=2) std::sort(V[i].begin(),V[i].end());
		for(int i=1;i<=a;i++)
		{
			long long int S = 0;
			for(int j=0;j<V[i].size();j++)
			{
				S *= MOD;
				S += V[i][j];
			}
			z[i] = (S>0?S:-S);
		}
		
		
		for(int i=1;i<=a;i++) y[i] = i;
		std::sort(y+1,y+a+1,cmp);
		
		int C = 1;
		int start = 1;
		for(int i=1;i<=a;i++)
		{
			if(z[y[i]]!=0)
			{
				start = i;
				sum[C] = x[y[i]];
				break;
			}
		}
		for(int i=start+1;i<=a;i++)
		{
			if(z[y[i-1]]!=z[y[i]]) C++, sum[C] = 0;
			sum[C] += x[y[i]];
		}
		
		long long int ans = sum[1];
		for(int i=2;i<=C;i++) ans = gcd(ans,sum[i]);
		printf("%lld\n",ans);
	}
}