#include <stdio.h>
#include <vector>
#include <set>
#include <queue>

struct str{
	long long int first;
	int second;
	int index;
};
bool operator<(str a, str b)
{
	return a.first>b.first;
}

std::pair<int,int> edge[300010];
std::vector<str> V[300010];
std::priority_queue<str> Q;
std::queue<int> Q2;
int check[300010];
long long int dist[300010];
std::set<int> S;
std::set< std::pair<int,int> > T[300010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back({e,f,i});
		V[e].push_back({d,f,i});
		edge[i] = std::make_pair(d,e);
	}
	
	Q.push({0,1,0});
	while(!Q.empty())
	{
		long long int s = Q.top().first;
		int t = Q.top().second;
		int k = Q.top().index;
		Q.pop();
		if(check[t]) continue;
		check[t] = 1;
		dist[t] = s;
		S.insert(k);
		for(int i=0;i<V[t].size();i++) Q.push({s+V[t][i].second,V[t][i].first,V[t][i].index});
	}
	S.erase(0);
	
	if(S.size()<=c)
	{
		printf("%d\n",S.size());
		for(std::set<int> ::iterator it = S.begin();it!=S.end();it++) printf("%d ",(*it));
	}
	else
	{
		for(std::set<int> ::iterator it = S.begin();it!=S.end();it++)
		{
			int s = edge[*it].first;
			int t = edge[*it].second;
			T[s].insert(std::make_pair(t,*it));
			T[t].insert(std::make_pair(s,*it));
		}
		for(int i=1;i<=a;i++) if(T[i].size()==1) Q2.push(i);
		while(S.size()>c)
		{
			int t = Q2.front();
			Q2.pop();
			if(t==1) continue;
			
			std::set< std::pair<int,int> > ::iterator it = T[t].begin();
			int s = (it->first);
			T[s].erase(std::make_pair(t,it->second));
			if(T[s].size()==1) Q2.push(s);
			
			S.erase(it->second);
			T[t].clear();
		}
		
		printf("%d\n",S.size());
		for(std::set<int> ::iterator it = S.begin();it!=S.end();it++) printf("%d ",(*it));
	}
}