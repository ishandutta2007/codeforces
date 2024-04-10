#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int next[200010],check[200010],up[200010];
int init(int k, int prev, int target)
{
	up[k] = prev;
	if(k==target) return 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(init(V[k][i],k,target)==1)
		{
			next[k] = V[k][i];
			return 1;
		}
	}
	return 0;
}

int func(int k, int prev)
{
	int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += func(V[k][i],k);
	}
	if(ans==0)
	{
		if(check[k]==1) return 2;
		else return 0;
	}
	else return ans+2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) next[i] = check[i] = up[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int e;
			scanf("%d",&e);
			check[e] = 1;
		}
		for(int i=1;i<a;i++)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			V[e].push_back(f);
			V[f].push_back(e);
		}
		
		init(c,0,d);
		
		int k = c;
		int ans = 0;
		while(1)
		{
			for(int i=0;i<V[k].size();i++)
			{
				if(V[k][i]==up[k]) continue;
				if(V[k][i]==next[k]) continue;
				ans += func(V[k][i],k);
			}
			if(k==d) break;
			else ans++,k = next[k];
		}
		printf("%d\n",ans);
	}
}