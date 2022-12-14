#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#define MOD 1000000009

int count[100010],count2[100010],check[100010];
std::vector<int> V[100010],V2[100010];
std::map< std::pair<int,int> , int> M;
std::set<int> S;
std::pair<int,int> P[100010];
std::vector<int> ans;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		M[std::make_pair(b,c)] = i;
		P[i] = std::make_pair(b,c);
	}
	for(int i=1;i<=a;i++)
	{
		int b = P[i].first;
		int c = P[i].second;
		if(M.find(std::make_pair(b-1,c-1))!=M.end())
		{
			int k = M[std::make_pair(b-1,c-1)];
			V[k].push_back(i);
			V2[i].push_back(k);
			count[k]++;
			count2[i]++;
		}
		if(M.find(std::make_pair(b,c-1))!=M.end())
		{
			int k = M[std::make_pair(b,c-1)];
			V[k].push_back(i);
			V2[i].push_back(k);
			count[k]++;
			count2[i]++;
		}
		if(M.find(std::make_pair(b+1,c-1))!=M.end())
		{
			int k = M[std::make_pair(b+1,c-1)];
			V[k].push_back(i);
			V2[i].push_back(k);
			count[k]++;
			count2[i]++;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(count2[V[i][j]]==1) goto u;
		}
		S.insert(i);
		u:;
	}
	
	std::set<int> ::iterator it;
	while(1)
	{
		int k;
		if(S.empty()) break;
		it = S.end();
		it--;
		k = (*it);
		S.erase(it);
		
		ans.push_back(k);
		check[k] = 1;
		for(int i=0;i<V2[k].size();i++)
		{
			if(check[V2[k][i]]) continue;
			int s = V2[k][i];
			for(int j=0;j<V[s].size();j++)
			{
				if(check[V[s][j]]) continue;
				if(count2[V[s][j]]==1) goto v1;
			}
			S.insert(s);
			v1:;
		}
		for(int i=0;i<V[k].size();i++)
		{
			if(check[V[k][i]]) continue;
			int s = V[k][i];
			count2[s]--;
			for(int j=0;j<V2[s].size();j++)
			{
				if(check[V2[s][j]]) continue;
				int t = V2[s][j];
				if(S.find(t)!=S.end()) S.erase(t);
				
				for(int l=0;l<V[t].size();l++)
				{
					if(check[V[t][l]]) continue;
					if(count2[V[t][l]]==1) goto w2;
				}
				S.insert(t);
				w2:;
			}
		}
		
		if(S.empty()) break;
		it = S.begin();
		k = (*it);
		S.erase(it);
		
		ans.push_back(k);
		check[k] = 1;
		for(int i=0;i<V2[k].size();i++)
		{
			if(check[V2[k][i]]) continue;
			int s = V2[k][i];
			for(int j=0;j<V[s].size();j++)
			{
				if(check[V[s][j]]) continue;
				if(count2[V[s][j]]==1) goto v2;
			}
			S.insert(s);
			v2:;
		}
		for(int i=0;i<V[k].size();i++)
		{
			if(check[V[k][i]]) continue;
			int s = V[k][i];
			count2[s]--;
			for(int j=0;j<V2[s].size();j++)
			{
				if(check[V2[s][j]]) continue;
				int t = V2[s][j];
				if(S.find(t)!=S.end()) S.erase(t);
				for(int l=0;l<V[t].size();l++)
				{
					if(check[V[t][l]]) continue;
					if(count2[V[t][l]]==1) goto w1;
				}
				S.insert(t);
				w1:;
			}
		}
	}
	
	//for(int i=0;i<ans.size();i++) printf("%d ",ans[i]-1);
	//printf("!!\n");
	long long int sum = 0;
	for(int i=0;i<ans.size();i++)
	{
		sum*=a, sum%=MOD;
		sum += (ans[i]-1), sum%=MOD;
	}
	printf("%lld",sum);
}