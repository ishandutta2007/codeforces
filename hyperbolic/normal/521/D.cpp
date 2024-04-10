#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

struct str{
	long long int first;
	long long int second;
	int index;
};
bool operator<(str a, str b)
{
	double A = (double)a.first/a.second;
	double B = (double)b.first/b.second;
	return A<B;
}

std::vector< std::pair<int,int> > V1[100010],V2[100010];
std::vector<str> V3;

long long int x[100010];
int type[100010];
std::vector<int> ans;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(d==1) V1[e].push_back(std::make_pair(f,i));
		if(d==2) V2[e].push_back(std::make_pair(f,i));
		if(d==3)
		{
			if(f==1) continue;
			V3.push_back({f,1,i});
		}
		type[i] = d;
	}
	for(int i=1;i<=a;i++)
	{
		if(!V1[i].empty())
		{
			std::sort(V1[i].begin(),V1[i].end());
			if( (V1[i].back().first) > x[i] ) V2[i].push_back(std::make_pair(V1[i].back().first-x[i],V1[i].back().second));
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(!V2[i].empty())
		{
			std::sort(V2[i].begin(),V2[i].end());
			for(int j=V2[i].size()-1;j>=0;j--)
			{
				V3.push_back({V2[i][j].first+x[i],x[i],V2[i][j].second});
				x[i] += V2[i][j].first;
			}
		}
	}
	std::sort(V3.begin(),V3.end());
	int C = V3.size()-1;
	for(int i=0;i<V3.size() && i<c;i++)
	{
		ans.push_back(V3[C].index);
		C--;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) if(type[ans[i]]==1) printf("%d ",ans[i]);
	for(int i=0;i<ans.size();i++) if(type[ans[i]]==2) printf("%d ",ans[i]);
	for(int i=0;i<ans.size();i++) if(type[ans[i]]==3) printf("%d ",ans[i]);
}