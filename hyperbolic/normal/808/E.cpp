#include <stdio.h>
#include <vector>
#include <algorithm>
std::vector<int> V[5];
long long int DP[300010];
std::pair<int,int> pos[300010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	V[1].push_back(0);
	V[2].push_back(0);
	V[3].push_back(0);
	std::sort(V[1].begin(),V[1].end());
	std::sort(V[2].begin(),V[2].end());
	std::sort(V[3].begin(),V[3].end());
	std::reverse(V[1].begin(),V[1].end());
	std::reverse(V[2].begin(),V[2].end());
	std::reverse(V[3].begin(),V[3].end());
	DP[0] = 0;
	DP[1] = V[1][0];
	pos[0] = {0,0};
	pos[1] = {1,0};
	for(int i=2;i<=b;i++) pos[i] = {V[1].size(),V[2].size()};
	for(int i=2;i<=b;i++)
	{
		if(pos[i-2].second!=V[2].size())
		{
			long long int t = DP[i-2] + V[2][pos[i-2].second];
			if(DP[i]<t)
			{
				DP[i] = t;
				pos[i] = {pos[i-2].first,pos[i-2].second+1};
			}
		}
		if(pos[i-1].first!=V[1].size())
		{
			long long int t = DP[i-1] + V[1][pos[i-1].first];
			if(DP[i]<t)
			{
				DP[i] = t;
				pos[i] = {pos[i-1].first+1,pos[i-1].second};
			}
		}
	}
	for(int i=1;i<=b;i++) DP[i] = DP[i]>DP[i-1]?DP[i]:DP[i-1];
	
	long long int ans = DP[b];
	long long int S = 0;
	for(int i=0;i<V[3].size();i++)
	{
		if(b-3*(i+1)<0) break;
		S += V[3][i];
		long long int t = S+DP[b-3*(i+1)];
		ans = ans>t?ans:t;
	}
	printf("%lld",ans);
}