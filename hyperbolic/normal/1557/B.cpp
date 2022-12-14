#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

std::vector<int> index;
std::map<int,int> hash;
int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		hash.clear();
		index.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		for(int i=1;i<=a;i++) y[i] = hash[x[i]];
		
		int count = 1;
		for(int i=1;i<a;i++) if(y[i+1]!=y[i]+1) count++;
		if(count<=b) printf("Yes\n");
		else printf("No\n");
	}
}