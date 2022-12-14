#include <stdio.h>
#include <vector>

struct str{
	int x1;
	int x2;
	int x3;
	int x4;
};

struct str2{
	int first;
	int second;
	int value;
};

std::vector<str> ans;
std::vector<int> V[100010];
int last;

std::pair<int,int> func(int k, int prev)
{
	if(k!=1 && V[k].size()==1) return std::make_pair(k,k);
	
	std::vector<str2> temp,temp2;
	int p = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		
		std::pair<int,int> P = func(V[k][i],k);
		if(P.first==V[k][i]) temp.push_back({P.first,P.second,V[k][i]});
		else temp2.push_back({P.first,P.second,V[k][i]});
	}
	
	if(temp.size()==0)
	{
		std::pair<int,int> t = {temp2[0].first,temp2[0].second};
		for(int i=1;i<temp2.size();i++)
		{
			ans.push_back({k,temp2[i].value,t.second,temp2[i].first});
			t.second = temp2[i].second;
		}
		ans.push_back({k,temp2[0].value,k,t.first});
		return {k,t.second};
	}
	else if(temp.size()==1)
	{
		std::pair<int,int> t = {temp[0].first,temp[0].second};
		for(int i=0;i<temp2.size();i++)
		{
			ans.push_back({k,temp2[i].value,t.second,temp2[i].first});
			t.second = temp2[i].second;
		}
		return {k,t.second};
	}
	else
	{
		std::pair<int,int> t = {temp[0].first,temp[0].second};
		for(int i=0;i<temp2.size();i++)
		{
			ans.push_back({k,temp2[i].value,t.second,temp2[i].first});
			t.second = temp2[i].second;
		}
		for(int i=2;i<temp.size();i++)
		{
			ans.push_back({k,temp[i].value,t.second,temp[i].first});
			t.second = temp[i].second;
		}
		return std::make_pair(t.second,temp[1].second);
	}
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
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
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d %d\n",ans[i].x1,ans[i].x2,ans[i].x3,ans[i].x4);
	}
	
}