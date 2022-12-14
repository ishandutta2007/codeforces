#include <stdio.h>
#include <vector>
#include <algorithm>

int height[300010];
int size[300010];
std::pair<int,int> next[300010][21];
std::vector< std::pair<int,int> > V[300010];
int check[300010],next2[300010];

std::pair<int,int> LCA(int s, int t)
{
	int ans = 0;
	if(height[s]>height[t])
	{
		int k = height[s] - height[t];
		for(int i=20;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				k -= (1<<i);
				ans ^= next[s][i].second;
				s = next[s][i].first;
			}
		}
	}
	if(height[t]>height[s])
	{
		int k = height[t] - height[s];
		for(int i=20;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				k -= (1<<i);
				ans ^= next[t][i].second;
				t = next[t][i].first;
			}
		}
	}
	
	for(int i=20;i>=0;i--)
	{
		if(next[s][i].first!=next[t][i].first)
		{
			ans ^= next[s][i].second;
			ans ^= next[t][i].second;
			s = next[s][i].first;
			t = next[t][i].first;
		}
	}
	if(s!=t)
	{
		ans ^= next[s][0].second;
		ans ^= next[t][0].second;
		s = next[s][0].first;
		t = next[t][0].first;
	}
	return std::make_pair(s,ans);
}

int init(int k, int prev, int h)
{
	check[k] = 1;
	size[k] = 1;
	height[k] = h;
	next[k][0] = std::make_pair(prev,0);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) next[k][0] = V[k][i];
		else size[k] += init(V[k][i].first,k,h+1);
	}
	return size[k];
}

int number[300010],up[300010],heavy[300010];

void init2(int k, int prev, int &C, int target)
{
	number[k] = C++;
	up[k] = target;
	int p = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		if(p==-1) p = V[k][i].first;
		else if(size[p] < size[V[k][i].first]) p = V[k][i].first;
	}
	if(p==-1) return;
	
	heavy[k] = p;
	init2(p,k,C,target);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		if(V[k][i].first==p) continue;
		init2(V[k][i].first,k,C,V[k][i].first);
	}
}

struct segTree{
	int value[1200010];
	int lazy[1200010];
	void setValue(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int doQuery(int s, int t, int type)
{
	//height[s] > height[t]
	//except t
	if(type==1) // setValue
	{
		while(height[up[s]]>height[t])
		{
			T.setValue(number[up[s]],number[s],1);
			s = next[up[s]][0].first;
		}
		T.setValue(number[t]+1,number[s],1);
		return -1;
	}
	else // getMax
	{
		int ans = 0;
		while(height[up[s]]>height[t])
		{
			int k = T.getMax(number[up[s]],number[s]);
			ans = ans>k?ans:k;
			s = next[up[s]][0].first;
		}
		int k = T.getMax(number[t]+1,number[s]);
		ans = ans>k?ans:k;
		return ans;
	}
}

int find(int k)
{
	if(k==next2[k]) return k;
	else return next2[k] = find(next2[k]);
}

struct str{
	int first;
	int second;
	int value;
}query[500010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		query[i]={c,d,e};
	}
	
	for(int i=1;i<=a;i++) next2[i] = i;
	
	for(int i=1;i<=b;i++)
	{
		int s = find(query[i].first);
		int t = find(query[i].second);
		if(s!=t)
		{
			V[query[i].first].push_back({query[i].second,query[i].value});
			V[query[i].second].push_back({query[i].first,query[i].value});
			next2[s] = t;
		}
	}
	
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			init(i,0,1);
			init2(i,0,C,i);
		}
	}
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			next[i][j].first = next[next[i][j-1].first][j-1].first;
			next[i][j].second = (next[next[i][j-1].first][j-1].second ^ next[i][j-1].second);
		}
	}
	
	for(int i=1;i<=a;i++) next2[i] = i;
	for(int i=1;i<=b;i++)
	{
		int s = query[i].first;
		int t = query[i].second;
		if(find(s)!=find(t))
		{
			printf("YES\n");
			next2[find(s)] = find(t);
		}
		else
		{
			std::pair<int,int> P = LCA(s,t);
			int u = P.first;
			int v = P.second;
			//printf("%d %d %d %d!!\n",s,t,u,v);
			if(doQuery(s,u,2)==0 && doQuery(t,u,2)==0 && (v^query[i].value)==1)
			{
				printf("YES\n");
				doQuery(s,u,1);
				doQuery(t,u,1);
			}
			else printf("NO\n");
		}
	}
}