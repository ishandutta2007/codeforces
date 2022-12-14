#include <stdio.h>
#include <map>

std::map<int,int> count;
int func(int k)
{
	int ans = 0;
	while(k)
	{
		ans++;
		k/=10;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[b]++;
		}
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[b]--;
		}
		
		int ans = 0;
		while(!count.empty())
		{
			std::map<int,int> ::iterator it = count.end();
			it--;
			int s = it->first, t = it->second;
			count.erase(it);
			if(t>0) ans+=t, count[func(s)] += t;
			if(t<0) ans-=t, count[func(s)] += t;
		}
		
		printf("%d\n",ans);
	}
}