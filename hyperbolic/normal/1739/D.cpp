#include <stdio.h>
#include <vector>
int h;

std::vector<int> V[200010];
std::pair<int,int> func(int k)
{
	int ans = 0;
	int max = 0;
	for(int i=0;i<V[k].size();i++)
	{
		std::pair<int,int> P  = func(V[k][i]);
		ans += P.first;
		if(P.second==h) ans++;
		else max = max>P.second?max:P.second;
	}
	return std::make_pair(ans,max+1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=2;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			V[c].push_back(i);
		}
		
		int ans = a;
		int min = 1, max = a;
		while(min<=max)
		{
			h = (min+max)/2;
			int sum = 0;
			for(int i=0;i<V[1].size();i++) sum += func(V[1][i]).first;
			if(sum<=b)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d\n",ans);
	}
}