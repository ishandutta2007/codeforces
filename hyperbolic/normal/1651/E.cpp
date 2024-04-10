#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[3010];
std::pair<int,int> edge[3010];

int next[3010],left[3010],right[3010],count[3010],size[3010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c-a);
	}
	
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	for(int i=1;i<=a;i++) edge[i] = std::make_pair(V[i][0],V[i][1]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int S = 0;
		for(int j=1;j<=a;j++) next[j] = j;
		for(int j=1;j<=a;j++) left[j] = right[j] = j;
		for(int j=1;j<=a;j++) count[j] = 0;
		for(int j=1;j<=a;j++) size[j] = 1;
		
		for(int j=i;j<=a;j++)
		{
			int s = edge[j].first;
			int t = edge[j].second;
			if(count[s]==0) S += s*(a-s+1);
			if(count[t]==0) S += t*(a-t+1);
			count[s]++, count[t]++;
			if(find(s)!=find(t))
			{
				if(size[find(s)]>1) S += left[find(s)] * (a-right[find(s)]+1);
				if(size[find(t)]>1) S += left[find(t)] * (a-right[find(t)]+1);
				int s2 = find(s), t2 = find(t);
				next[s2] = t2;
				size[t2] += size[s2];
				left[t2] = left[t2]<left[s2]?left[t2]:left[s2];
				right[t2] = right[t2]>right[s2]?right[t2]:right[s2];
				S -= left[t2] * (a-right[t2]+1);
			}
			else
			{
				int t2 = find(t);
				S += left[t2] * (a-right[t2]+1);
			}
			ans += S;
		}
	}
	printf("%lld",ans);
}