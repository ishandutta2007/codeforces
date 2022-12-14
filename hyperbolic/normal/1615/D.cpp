#include <stdio.h>
#include <vector>

int parity(int k)
{
	int ans = 0;
	while(k) ans+=k%2, k/=2;
	return ans%2;
}

int next[400010];
int check[400010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

struct str{
	int first;
	int second;
	int index;
}edge[200010];

std::vector<str> V[200010];
int a;
void init(int k, int p, int val)
{
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		if(V[k][i].second==-1)
		{
			int val1 = check[find(V[k][i].first)];
			int val2 = check[find(V[k][i].first+a)];
			if(val1==1)
			{
				edge[V[k][i].index].index = val;
				init(V[k][i].first,k,0);
			}
			if(val2==1)
			{
				edge[V[k][i].index].index = (1^val);
				init(V[k][i].first,k,1);
			}
		}
		else init(V[k][i].first,k,(val^parity(V[k][i].second)));
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=2*a;i++) next[i] = i;
		for(int i=1;i<=2*a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			edge[i] = {c,d,e};
			V[c].push_back({d,e,i});
			V[d].push_back({c,e,i});
			if(e!=-1)
			{
				int c2,d2;
				if(parity(e)==0)
				{
					c2 = find(c), d2 = find(d);
					next[c2] = d2;
					c2 = find(c+a), d2 = find(d+a);
					next[c2] = d2;
				}
				else
				{
					c2 = find(c), d2 = find(a+d);
					next[c2] = d2;
					c2 = find(c+a), d2 = find(d);
					next[c2] = d2;
				}
			}
		}
		
		for(int i=1;i<=b;i++)
		{
			int c2,d2;
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			if(e==0)
			{
				c2 = find(c), d2 = find(d);
				next[c2] = d2;
				c2 = find(c+a), d2 = find(d+a);
				next[c2] = d2;
			}
			else
			{
				c2 = find(c), d2 = find(a+d);
				next[c2] = d2;
				c2 = find(c+a), d2 = find(d);
				next[c2] = d2;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(find(i)==find(a+i))
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		
		for(int i=1;i<=a;i++)
		{
			int s = find(i);
			int t = find(a+i);
			if(check[s]==0) check[s] = 1, check[t] = -1;
		}
		
		init(1,0,0);
		for(int i=1;i<a;i++) printf("%d %d %d\n",edge[i].first,edge[i].second,edge[i].index);
		u:;
	}
}