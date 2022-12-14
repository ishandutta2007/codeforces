#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::map<int,int> hash;
std::vector<int> index;

int x[100010];
std::vector<int> V[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		for(int i=1;i<=a;i++) V[hash[x[i]]].push_back(i);
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			long long int S = 0;
			for(int j=0;j<V[i].size();j++)
			{
				ans += S*(a-V[i][j]+1);
				S += V[i][j];
			}
		}
		
		printf("%lld\n",ans);
		
		for(int i=1;i<=a;i++) V[i].clear();
		index.clear();
		hash.clear();
	}
}