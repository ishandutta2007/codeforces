#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<int,int> > V[300010];
int height[300010],use[300010];
std::pair<int,int> prev[300010];

void init(int k, int p, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(height[V[k][i].first]>0) continue;
		prev[V[k][i].first] = std::make_pair(k,V[k][i].second);
		use[V[k][i].second] = 1;
		init(V[k][i].first,k,h+1);
	}
}

std::vector<int> path;
void getPath(int s, int t)
{
	path.clear();
	std::vector<int> save1,save2;
	
	while(s!=t)
	{
		if(height[s]>=height[t])
		{
			save1.push_back(prev[s].second);
			s = prev[s].first;
		}
		else
		{
			save2.push_back(prev[t].second);
			t = prev[t].first;
		}
	}
	std::reverse(save2.begin(),save2.end());
	for(int i=0;i<save1.size();i++) path.push_back(save1[i]);
	for(int i=0;i<save2.size();i++) path.push_back(save2[i]);
}

int ans;
int count[300010];
int func(int k, int p)
{
	int sum = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		if(use[V[k][i].second]==0) continue;
		sum += func(V[k][i].first,k);
	}
	
	ans += sum/2;
	sum%=2;
	
	if(count[prev[k].second]%2==1) return 1;
	else
	{
		if(sum>0) ans++;
		return 0;
	}
}

std::pair<int,int> edge[300010],query[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(std::make_pair(d,i));
		V[d].push_back(std::make_pair(c,i));
		edge[i] = std::make_pair(c,d);
	}
	
	init(1,0,1);
	
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		query[i] = std::make_pair(d,e);
		getPath(d,e);
		for(int j=0;j<path.size();j++) count[path[j]]++;
	}
	
	int control = 1;
	for(int i=1;i<=b;i++) if(count[i]%2==1) control = 0;
	
	if(control==1)
	{
		printf("YES\n");
		for(int i=1;i<=c;i++)
		{
			int s = query[i].first, t = query[i].second;
			getPath(s,t);
			printf("%d\n",path.size()+1);
			printf("%d ",s);
			for(int j=0;j<path.size();j++)
			{
				if(s==edge[path[j]].first) s = edge[path[j]].second;
				else s = edge[path[j]].first;
				printf("%d ",s);
			}
			printf("\n");
		}
	}
	else
	{
		printf("NO\n");
		func(1,0);
		printf("%d",ans);
	}
	
}