#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int check[200010],height[200010],prev[200010],up[200010];
void init(int k, int p, int h)
{
	check[k] = 1;
	prev[k] = p;
	height[k] = h;
	up[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		if(check[V[k][i]]==1) up[k] = up[k]<height[V[k][i]]?up[k]:height[V[k][i]];
		else init(V[k][i],k,h+1);
	}
	for(int i=0;i<V[k].size();i++) if(height[V[k][i]]==height[k]+1) up[k] = up[k]<up[V[k][i]]?up[k]:up[V[k][i]];
}

int check2[200010];
int getSize(int k)
{
	if(check2[k]) return 0;
	check2[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev[k]) continue;
		if(height[V[k][i]]==height[k]+1) ans += getSize(V[k][i]);
	}
	return ans;
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
		for(int i=1;i<=a;i++) up[i] = check2[i] = height[i] = check[i] = prev[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			V[e].push_back(f);
			V[f].push_back(e);
		}
		init(c,0,1);
		
		int p1 = -1, p2 = d;
		while(p2!=c)
		{
			p1 = p2;
			p2 = prev[p2];
		}
		
		long long int ans1 = 0, ans2 = 0;
		for(int i=0;i<V[c].size();i++) if(V[c][i]!=p1&&height[V[c][i]]==height[c]+1) ans1 += getSize(V[c][i]);
		for(int i=0;i<V[d].size();i++)
		{
			if(V[d][i]==prev[d]) continue;
			if(height[V[d][i]]==height[d]+1 && up[V[d][i]]>=height[d]) ans2 += getSize(V[d][i]);
		}
		//printf("%lld %lld!!\n",ans1,ans2);
		
		printf("%lld\n",ans1*ans2);
	}
}