#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

long long int x[200010];
int y[200010];
std::vector<int> index;
std::map<int,int> hash;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) y[i] = 0;
		index.clear();
		hash.clear();
		
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i;
		for(int i=1;i<=a;i++) y[hash[x[i]]]++;
		
		int ans = 0;
		for(int i=0;i<index.size();i++) ans = ans>y[i]?ans:y[i];
		
		for(int i=0;i+1<index.size();i++)
		{
			long long int gap = index[i+1]-index[i];
			long long int start = index[i+1];
			int count = y[i]+1;
			int last = i+1;
			while(1)
			{
				long long int target = start+gap;
				int min = last+1, max = index.size()-1;
				int p = a+1;
				while(min<=max)
				{
					int h = (min+max)/2;
					if(index[h]>=target)
					{
						p = h;
						max = h-1;
					}
					else min = h+1;
				}
				if(p==a+1) break;
				else
				{
					count++;
					gap+=(index[p]-index[last]);
					last = p;
					start = index[p];
				}
			}
			ans = ans>count?ans:count;
		}
		printf("%d\n",a-ans);
	}
}