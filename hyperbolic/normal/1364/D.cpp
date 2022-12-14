#include <stdio.h>
#include <vector>


std::vector <int> V[100010],V2[5];
int level[100010],parent[100010];

void func(int s, int t, int h)
{
	if(level[s]) return;
	level[s] = h;
	parent[s] = t;
	for(int i=0;i<V[s].size();i++) func(V[s][i],s,h+1);
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	func(1,0,1);
	
	int ans = 12345678;
	std::pair<int,int> ans2 = std::make_pair(0,0);
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			int next = V[i][j];
			if(level[next]<=level[i]-2)
			{
				if(level[i]-level[next]+1<ans)
				{
					ans = level[i] - level[next] + 1;
					ans2 = std::make_pair(i,next);
				}
			}
		}
	}
	
	if(ans==12345678)
	{
		for(int i=1;i<=a;i++) V2[level[i]%2].push_back(i);
		if(V2[0].size()>=(c+1)/2)
		{
			printf("1\n");
			for(int i=0;i<(c+1)/2;i++) printf("%d ",V2[0][i]);
		}
		else
		{
			printf("1\n");
			for(int i=0;i<(c+1)/2;i++) printf("%d ",V2[1][i]);
		}
	}
	else
	{
		if(ans<=c)
		{
			printf("2\n%d\n",ans);
			int p = ans2.first;
			while(1)
			{
				printf("%d ",p);
				if(p==ans2.second) break;
				p = parent[p];
			}
		}
		else
		{
			printf("1\n");
			int p = ans2.first;
			for(int i=0;i<(c+1)/2;i++)
			{
				printf("%d ",p);
				p = parent[parent[p]];
			}
		}
	}
}