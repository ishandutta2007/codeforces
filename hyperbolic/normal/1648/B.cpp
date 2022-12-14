#include <stdio.h>
#include <vector>
#include <algorithm>

int count[1000010],x[1000010];
std::vector<int> index;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		if(x[1]>1)
		{
			printf("No\n");
			continue;
		}
		
		for(int i=1;i<=b;i++) count[i] = 0;
		for(int i=1;i<=a;i++) count[x[i]] = 1;
		for(int i=1;i<=b;i++) count[i] += count[i-1];
		
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++)
		{
			for(int j=index[i];j<=b;j+=index[i])
			{
				int t = j+index[i]-1;
				t = t<b?t:b;
				if(count[t] - count[j-1] >=1 && count[j/index[i]]-count[j/index[i]-1]==0)
				{
					printf("No\n");
					goto u;
				}
			}
		}
		printf("Yes\n");
		u:;
	}
}