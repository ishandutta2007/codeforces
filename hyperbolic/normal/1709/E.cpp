#include <stdio.h>
#include <vector>
#include <set>

int size[200010],heavy[200010],value[200010],x[200010];
int up[200010];
std::vector<int> V[200010];
std::set<int> S[200010];
int init(int k, int prev, int t)
{
	size[k] = 1;
	heavy[k] = -1;
	t ^= x[k];
	value[k] = t;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int val = init(V[k][i],k,t);
		if(heavy[k]==-1) heavy[k] = V[k][i];
		else if(size[heavy[k]] < val) heavy[k] = V[k][i];
		size[k] += val;
	}
	return size[k];
}

void init2(int k, int prev, int target)
{
	up[k] = target;
	if(heavy[k]!=-1) init2(heavy[k],k,target);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(V[k][i]==heavy[k]) continue;
		init2(V[k][i],k,V[k][i]);
	}
}

int ans = 0;
void func(int k, int prev)
{
	int control = 0;
	if(heavy[k]!=-1)
	{
		func(heavy[k],k);
		if(S[up[k]].find(value[prev])!=S[up[k]].end()) control = 1;
	}
	S[up[k]].insert(value[k]);
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(V[k][i]==heavy[k]) continue;
		func(V[k][i],k);
		for(std::set<int> ::iterator it = S[V[k][i]].begin();it!=S[V[k][i]].end();it++)
		{
			if(S[up[k]].find((*it)^value[k]^value[prev])!=S[up[k]].end())
			{
				control = 1;
			}
		}
		for(std::set<int> ::iterator it = S[V[k][i]].begin();it!=S[V[k][i]].end();it++) S[up[k]].insert(*it);
		S[V[k][i]].clear();
	}
	if(control)
	{
		ans++;
		S[up[k]].clear();
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	init(1,0,0);
	init2(1,0,1);
	func(1,0);
	printf("%d",ans);
}