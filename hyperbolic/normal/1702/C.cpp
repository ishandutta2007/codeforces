#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

std::vector<int> index;
std::map<int,int> hash;
int min[200010],max[200010],x[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		hash.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		for(int i=1;i<=a;i++) min[i] = a+1, max[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int t = hash[x[i]];
			min[t] = min[t]<i?min[t]:i;
			max[t] = max[t]>i?max[t]:i;
		}
		
		while(b--)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(hash.find(c)==hash.end()) printf("NO\n");
			else if(hash.find(d)==hash.end()) printf("NO\n");
			else
			{
				c = hash[c];
				d = hash[d];
				if(min[c]<=max[d]) printf("YES\n");
				else printf("NO\n");
			}
		}
		
	}
}