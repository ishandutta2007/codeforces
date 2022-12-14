#include <stdio.h>
#include <vector>
#include <map>
std::vector<int> save;
std::pair<int,int> edge[200010];
std::vector< std::pair<int,int> > V[200010];

int prev[200010],height[200010],ans[200010];
void init(int k, int p, int h)
{
	prev[k] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		if(height[V[k][i].first]!=0&&height[V[k][i].first]<h) save.push_back(V[k][i].second);
		if(height[V[k][i].first]==0) init(V[k][i].first,k,h+1);
	}
}

std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		save.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) height[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			edge[i] = std::make_pair(c,d);
			V[c].push_back(std::make_pair(d,i));
			V[d].push_back(std::make_pair(c,i));
		}
		
		init(1,0,1);
		if(save.size()<=2)
		{
			for(int i=1;i<=b;i++) ans[i] = 0;
			for(int i=0;i<save.size();i++) ans[save[i]] = 1;
			
			for(int i=1;i<=b;i++) printf("%d",ans[i]);
			printf("\n");
		}
		else
		{
			for(int i=0;i<save.size();i++) M[edge[save[i]].first]++, M[edge[save[i]].second]++;
			if(M.size()>3)
			{
				for(int i=1;i<=b;i++) ans[i] = 0;
				for(int i=0;i<save.size();i++) ans[save[i]] = 1;
				
				for(int i=1;i<=b;i++) printf("%d",ans[i]);
				printf("\n");
			}
			else
			{
				int p = -1;
				for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
				{
					if(p==-1) p = (it->first);
					else if(height[p]>height[it->first]) p = (it->first);
				}
				
				int c1, c2;
				for(int i=1;i<=b;i++) ans[i] = 0;
				for(int i=0;i<save.size();i++) ans[save[i]] = 1;
				
				int temp = edge[save[0]].first;
				if(temp==p) temp = edge[save[0]].second;
				while(prev[temp]!=p) temp = prev[temp];
				for(int i=0;i<V[p].size();i++) if(V[p][i].first==temp) c1 = V[p][i].second;
				for(int i=0;i<save.size();i++) if(edge[save[i]].first==p || edge[save[i]].second==p) c2 = save[i];
				ans[c1] = 1;
				ans[c2] = 0;
				
				for(int i=1;i<=b;i++) printf("%d",ans[i]);
				printf("\n");
			}
		}
	}
}