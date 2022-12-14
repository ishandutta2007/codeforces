#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> index;
int main()
{
	for(int i=1;i<=40000;i++) index.push_back(i*i);
	for(int i=1;i<=1000;i++) index.push_back(i*i*i);
	
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int ans = 0;
		for(int i=0;i<index.size();i++) if(index[i]<=a) ans++;
		printf("%d\n",ans);
	}
}