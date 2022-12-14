#include <stdio.h>
#include <algorithm>
#include <set>

struct str{
	int first;
	int second;
	int value;
}edge[200010];
std::vector<str> edge2;

bool cmp(str a, str b)
{
	return a.value<b.value;
}

int next[2010],next2[2010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}
int find2(int k)
{
	if(k==next2[k]) return k;
	else return next2[k] = find2(next2[k]);
}
int check[2010][2010];
std::set<int> S[2010];

int count[200010], next3[200010], hash[200010];
std::vector<int> V;
int find3(int k)
{
	if(k==next3[k]) return k;
	else return next3[k] = find3(next3[k]);
}

int check2[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>=2000)
	{
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			count[c]++, count[d]++;
			edge[i] = {c,d,e};
		}
		
		int p = 1;
		for(int i=1;i<=a;i++) if(count[i]<count[p]) p = i;
		for(int i=1;i<=a;i++) next3[i] = i;
		for(int i=1;i<=b;i++)
		{
			if(edge[i].first==p) check2[edge[i].second] = 1;
			if(edge[i].second==p) check2[edge[i].first] = 1;
		}
		for(int i=1;i<=a;i++)
		{
			if(i==p) continue;
			if(check2[i]==0)
			{
				int s = find3(p);
				int t = find3(i);
				next3[t] = s;
			}
		}
		
		V.push_back(p);
		for(int i=1;i<=a;i++)
		{
			if(i==p) continue;
			if(next3[i]==i) V.push_back(i);
		}
		for(int i=0;i<V.size();i++) hash[V[i]] = i;
		
		for(int i=1;i<=b;i++)
		{
			int s = find3(edge[i].first);
			int t = find3(edge[i].second);
			check[hash[s]][hash[t]]++, check[hash[t]][hash[s]]++;
			edge2.push_back({hash[s],hash[t],edge[i].value});
		}
		
		for(int i=1;i<V.size();i++)
		{
			for(int j=i+1;j<V.size();j++)
			{
				if(check[i][j]==0) edge2.push_back({i,j,0});
			}
		}
		for(int i=1;i<V.size();i++) if(check[0][i]<a-count[p]) edge2.push_back({0,i,0});
		
		std::sort(edge2.begin(),edge2.end(),cmp);
		long long int sum = 0;
		
		for(int i=0;i<=a;i++) next3[i] = i;
		for(int i=0;i<edge2.size();i++)
		{
			int s = find3(edge2[i].first);
			int t = find3(edge2[i].second);
			if(s!=t)
			{
				sum += edge2[i].value;
				next3[t] = s;
			}
		}
		printf("%lld",sum);
		return 0;
	}
	
	int T = 0;
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		edge[i] = {c,d,e};
		check[c][d] = check[d][c] = 1;
		T ^= e;
	}
	
	for(int i=1;i<=a;i++) next[i] = i;
	int control = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(check[i][j]==0)
			{
				int s = find(i);
				int t = find(j);
				if(s==t) control = 1;
				else next[s] = t;
			}
		}
	}
	
	long long int sum = 0;
	int control2 = 0;
	if(control==0) control2 = 1, sum = T;
	
	std::sort(edge+1,edge+b+1,cmp);
	for(int i=1;i<=a;i++) next2[i] = i;
	for(int i=1;i<=b;i++)
	{
		int s = find2(find(edge[i].first));
		int t = find2(find(edge[i].second));
		if(control2==1 && find(edge[i].first)==find(edge[i].second) && edge[i].value<T)
		{
			sum -= T, sum += edge[i].value;
			control2 = 0;
		}
		
		if(s!=t)
		{
			S[find(edge[i].first)].insert(edge[i].first);
			S[find(edge[i].second)].insert(edge[i].second);
			sum += edge[i].value;
			next2[s] = t;
		}
		else if(edge[i].value<T)
		{
			if(control2==1)
			{
				if(S[find(edge[i].first)].size()>=2)
				{
					sum -= T, sum += edge[i].value;
					control2 = 0;
				}
				else if(S[find(edge[i].first)].size()==1)
				{
					std::set<int> ::iterator it = S[find(edge[i].first)].begin();
					if((*it)!=edge[i].first)
					{
						sum -= T, sum += edge[i].value;
						control2 = 0;
					}
				}
			}
			
			if(control2==1)
			{
				if(S[find(edge[i].second)].size()>=2)
				{
					sum -= T, sum += edge[i].value;
					control2 = 0;
				}
				else if(S[find(edge[i].second)].size()==1)
				{
					std::set<int> ::iterator it = S[find(edge[i].second)].begin();
					if((*it)!=edge[i].second)
					{
						sum -= T, sum += edge[i].value;
						control2 = 0;
					}
				}
			}
		}
	}
	printf("%lld",sum);
}