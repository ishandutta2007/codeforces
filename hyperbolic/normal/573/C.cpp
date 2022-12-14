#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
std::set<int> S[100010],S2[100010];
std::vector<int> V[100010];
int count[100010],check[100010];
std::queue<int> Q;
 
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		S[b].insert(c);
		S[c].insert(b);
		S2[b].insert(c);
		S2[c].insert(b);
	}
	
	for(int i=1;i<=a;i++)
	{
		if(S[i].size()==2)
		{
			check[i] = 1;
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		check[k] = 0;
		
		std::set<int> ::iterator it = S[k].begin();
		int s = (*it);
		it++;
		int t = (*it);
		S[s].erase(k);
		S[t].erase(k);
		S[s].insert(t);
		S[t].insert(s);
		S[k].clear();
		if(S[s].size()==2 && check[s]==0) check[s]=1,Q.push(s);
		if(S[t].size()==2 && check[t]==0) check[t]=1,Q.push(t);
	}
	for(int i=1;i<=a;i++) for(std::set<int> ::iterator it = S[i].begin();it!=S[i].end();it++) V[i].push_back(*it);
	
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()==3)
		{
			int s = V[i][0], t = V[i][1], k = V[i][2];
			int c = 0;
			if(V[s].size()==1) c++;
			if(V[t].size()==1) c++;
			if(V[k].size()==1) c++;
			if(c>=2) check[i] = 2;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()>=3)
		{
			int c = 0;
			for(int j=0;j<V[i].size();j++)
			{
				if(V[V[i][j]].size()>=4) c++;
				if(V[V[i][j]].size()==3 && check[V[i][j]]!=2) c++;
				if(V[V[i][j]].size()==3 && check[V[i][j]]==2 && S2[i].find(V[i][j])==S2[i].end()) c++;
			}
			if(c>2)
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
}