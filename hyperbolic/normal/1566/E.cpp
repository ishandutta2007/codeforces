#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
std::pair<int,int> func(int k, int prev) // type,num
{
	int count1 = 0, count2 = 0;
	int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		count2++;
		std::pair<int,int> P = func(V[k][i],k);
		if(P.first==1) count1++;
		ans += P.second;
	}
	
	if(count2==0) return std::make_pair(1,1);
	else
	{
		if(count1==0) return std::make_pair(1,ans-count2+1);
		else return std::make_pair(0,ans-(count2-count1));
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		std::pair<int,int> P = func(1,0);
		printf("%d\n",P.second);
	}
}