#include <stdio.h>
#include <vector>

int dist[200010],dist2[200010],x[200010];
std::vector<int> V[200010];
void init(int k, int prev, int d)
{
	dist[k] = d;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,d+1);
	}
}

int init2(int k, int prev)
{
	if(x[k]) dist2[k] = 0;
	else
	{
		dist2[k] = -1;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			int t = init2(V[k][i],k);
			if(t!=-1)
			{
				if(dist2[k]==-1) dist2[k] = t+1;
				else dist2[k] = dist2[k]<t+1?dist2[k]:t+1;
			}
		}
	}
	return dist2[k];
}

int func(int k, int prev)
{
	if(dist2[k]==-1) return -1;
	
	if(dist[k]>=dist2[k]) return 1;
	else
	{
		int C = 0;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			int t = func(V[k][i],k);
			if(t==-1) return -1;
			else C+=t;
		}
		return C;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) x[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			x[c] = 1;
		}
		
		for(int i=1;i<a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		
		init(1,0,0);
		init2(1,0);
		int t = func(1,0);
		if(t==-1) printf("YES\n");
		else printf("NO\n");
		//printf("%d\n",t);
	}
}