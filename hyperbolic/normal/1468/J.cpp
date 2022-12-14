#include <stdio.h>
#include <algorithm>
#define MAX 1234567890

int next[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

struct str{
	int first;
	int second;
	int cost;
}edge[200010];
bool cmp(str a, str b)
{
	return a.cost<b.cost;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=b;i++)
		{
			int d,e,f;
			scanf("%d%d%d",&d,&e,&f);
			edge[i]={d,e,f};
		}
		
		for(int i=1;i<=a;i++) next[i] = i;
		long long int ans1 = MAX;
		for(int i=1;i<=b;i++)
		{
			if(edge[i].cost<=c)
			{
				int s = find(edge[i].first);
				int t = find(edge[i].second);
				if(s!=t) next[s] = t;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(find(i)!=find(1))
			{
				ans1 = -1;
				goto u;
			}
		}
		
		for(int i=1;i<=b;i++) if(edge[i].cost<=c) ans1 = ans1<c-edge[i].cost?ans1:c-edge[i].cost;
		u:;
		
		std::sort(edge+1,edge+b+1,cmp);
		for(int i=1;i<=a;i++) next[i] = i;
		long long int ans2 = 0;
		for(int i=1;i<=b;i++)
		{
			int s = find(edge[i].first);
			int t = find(edge[i].second);
			if(s!=t)
			{
				ans2 += (edge[i].cost<c?0:edge[i].cost-c);
				next[s] = t;
			}
		}
		if(ans2==0)
		{
			for(int i=1;i<=b;i++)
			{
				if(edge[i].cost>c)
				{
					ans2 = edge[i].cost-c;
					goto v;
				}
			}
			ans2 = -1;
		}
		v:;
		
		if(ans1==-1) printf("%lld\n",ans2);
		else if(ans2==-1) printf("%lld\n",ans1);
		else printf("%lld\n",ans1<ans2?ans1:ans2);
	}
}