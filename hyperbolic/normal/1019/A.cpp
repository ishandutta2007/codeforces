#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> V[3010];
long long int sum[3010][3010];
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
	for(int i=1;i<=b;i++) std::sort(V[i].begin(),V[i].end());
	for(int i=1;i<=b;i++)
	{
		if(V[i].size()>=1)
		{
			sum[i][0] = V[i][0];
			for(int j=1;j<V[i].size();j++) sum[i][j] = sum[i][j-1] + V[i][j];
		}
	}
	
	long long int ans = 1;
	for(int i=1;i<=15;i++) ans *= 10;
	
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		long long int S = 0;
		for(int j=2;j<=b;j++)
		{
			if(V[j].size()<i) continue;
			else
			{
				count += V[j].size()-i+1;
				S += sum[j][V[j].size()-i];
			}
		}
		
		if(count+V[1].size()>=i) ans = ans<S?ans:S;
		else
		{
			std::multiset<int> Set;
			for(int j=2;j<=b;j++)
			{
				if(V[j].size()<i) for(int k=0;k<V[j].size();k++) Set.insert(V[j][k]);
				else for(int k=V[j].size()-i+1;k<V[j].size();k++) Set.insert(V[j][k]);
			}
			int n = i - (count+V[1].size());
			while(n--)
			{
				std::multiset<int> ::iterator it = Set.begin();
				if(it==Set.end()) goto u;
				S += (*it);
				Set.erase(it);
			}
			ans = ans<S?ans:S;
			
			u:;
		}
	}
	printf("%lld",ans);
}