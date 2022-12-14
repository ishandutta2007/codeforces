#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int value;
	int index;
}x[500010];
bool cmp(str a, str b)
{
	return a.value<b.value;
}

int next[1010],color[1010];

int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		x[i] = {d,e,f,i};
	}
	std::sort(x+1,x+b+1,cmp);
	
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		
		for(int i=1;i<=a;i++) next[i] = i;
		for(int i=1;i<=a;i++) color[i] = 1;
		for(int i=b;i>=1;i--)
		{
			if(x[i].index<d || x[i].index>e) continue;
			
			int s = x[i].first;
			int t = x[i].second;
			int val = x[i].value;
			
			if(find(s)!=find(t))
			{
				if(color[s]==color[t])
				{
					for(int j=1;j<=a;j++) if(find(j)==find(s)) color[j] = 3-color[j];
				}
				next[find(s)] = find(t);
			}
			else
			{
				if(color[s]==color[t])
				{
					printf("%d\n",val);
					goto u;
				}
			}
		}
		printf("-1\n");
		u:;
	}
}