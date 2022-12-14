#include <stdio.h>
#include <queue>
#include <vector>

int next[300010],len[300010];
int find(int k)
{
	if(next[k]==k) return k;
	else return next[k] = find(next[k]);
}

std::queue<int> Q;
int dist1[300010],dist2[300010];
std::vector<int> V[300010];

int func(int k)
{
	int t = k;
	Q.push(k);
	dist1[k] = 1;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		t = k;
		for(int i=0;i<V[k].size();i++)
		{
			if(dist1[V[k][i]]==0)
			{
				dist1[V[k][i]] = dist1[k] + 1;
				Q.push(V[k][i]);
			}
		}
	}
	
	Q.push(t);
	dist2[t] = 1;
	int ans = 1;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		ans = dist2[k];
		
		for(int i=0;i<V[k].size();i++)
		{
			if(dist2[V[k][i]]==0)
			{
				dist2[V[k][i]] = dist2[k] + 1;
				Q.push(V[k][i]);
			}
		}
	}
	return ans-1;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=a;i++) len[i] = 0;
	
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
		
		if(find(d)!=find(e)) next[find(d)] = find(e);
	}
	for(int i=1;i<=a;i++) if(find(i)==i) len[i] = func(i);
	
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e;
			scanf("%d",&e);
			printf("%d\n",len[find(e)]);
		}
		else
		{
			int e,f;
			scanf("%d%d",&e,&f);
			e = find(e);
			f = find(f);
			if(e==f);
			else
			{
				next[e] = f;
				len[f] = len[f]>(len[f]+1)/2 + 1 + (len[e]+1)/2?len[f]:(len[f]+1)/2 + 1 + (len[e]+1)/2;
				len[f] = len[f]>len[e]?len[f]:len[e];
			}
		}
	}
}