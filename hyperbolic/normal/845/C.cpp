#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int sum[400010];
std::pair<int,int> x[200010];
std::vector<int> index;
std::map<int,int> hash;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
	for(int i=1;i<=a;i++)
	{
		index.push_back(x[i].first);
		index.push_back(x[i].second);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=a;i++)
	{
		sum[hash[x[i].first]]++;
		sum[hash[x[i].second]+1]--;
	}
	
	for(int i=1;i<=400000;i++) sum[i] += sum[i-1];
	
	for(int i=1;i<=400000;i++)
	{
		if(sum[i]>2)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}