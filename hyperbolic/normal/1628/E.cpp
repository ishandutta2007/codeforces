#include <stdio.h>
#include <vector>

int a;
std::vector< std::pair<int,int> > V[300010];
int height[300010];
std::pair<int,int> next[300010][21];

void init(int k, int p, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		next[V[k][i].first][0] = std::make_pair(k,V[k][i].second);
		init(V[k][i].first,k,h+1);
	}
}

int LCA(int s, int t)
{
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		for(int j=20;j>=0;j--)
		{
			if(k>=(1<<j))
			{
				k -= (1<<j);
				s = next[s][j].first;
			}
		}
	}
	if(height[t]>height[s])
	{
		int k = height[t]-height[s];
		for(int j=20;j>=0;j--)
		{
			if(k>=(1<<j))
			{
				k -= (1<<j);
				t = next[t][j].first;
			}
		}
	}
	
	for(int j=20;j>=0;j--)
	{
		if(next[s][j].first!=next[t][j].first)
		{
			s = next[s][j].first;
			t = next[t][j].first;
		}
	}
	if(s!=t) return next[s][0].first;
	else return s;
}

int getMax(int s, int t)
{
	// s -> t
	int k = height[s]-height[t];
	int ans = -1;
	for(int j=20;j>=0;j--)
	{
		if(k>=(1<<j))
		{
			int val = next[s][j].second;
			ans = ans>val?ans:val;
			s = next[s][j].first;
			k -= (1<<j);
		}
	}
	return ans;
}


struct segTree{
	std::pair<int,int> value[1200010];
	int mode[1200010];
	std::pair<int,int> on[1200010];
	
	void update(int k)
	{
		std::pair<int,int> P1 = value[2*k];
		std::pair<int,int> P2 = value[2*k+1];
		if(P1.first==-1)
		{
			value[k] = P2;
			return;
		}
		if(P2.first==-1)
		{
			value[k] = P1;
			return;
		}
		
		int M = P1.second>P2.second?P1.second:P2.second;
		int L = LCA(P1.first,P2.first);
		int temp = getMax(P1.first,L);
		M = M>temp?M:temp;
		temp = getMax(P2.first,L);
		M = M>temp?M:temp;
		value[k] = std::make_pair(L,M);
	}
	
	void update2(int k)
	{
		std::pair<int,int> P1 = on[2*k];
		std::pair<int,int> P2 = on[2*k+1];
		if(P1.first==-1)
		{
			on[k] = P2;
			return;
		}
		if(P2.first==-1)
		{
			on[k] = P1;
			return;
		}
		
		int M = P1.second>P2.second?P1.second:P2.second;
		int L = LCA(P1.first,P2.first);
		int temp = getMax(P1.first,L);
		M = M>temp?M:temp;
		temp = getMax(P2.first,L);
		M = M>temp?M:temp;
		on[k] = std::make_pair(L,M);
	}
	
	void init(int l=1, int r=300000, int v=1)
	{
		mode[v] = 0;
		value[v] = std::make_pair(-1,-1);
		if(l==r) on[v] = std::make_pair(l,-1);
		else
		{
			int h = (l+r)/2;
			value[2*v] = value[2*v+1] = std::make_pair(-1,-1);
			on[2*v] = on[2*v+1] = std::make_pair(-1,-1);
			init(l,h,2*v);
			init(h+1,r,2*v+1);
			update2(v);
		}
	}
	
	void doQuery(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		//printf("%d %d %d %d %d %d!!\n",L,R,val,l,r,v);
		if(L<=l&&r<=R)
		{
			if(val==1)
			{
				mode[v] = 1;
				value[v] = on[v];
			}
			else
			{
				mode[v] = 0;
				value[v] = std::make_pair(-1,-1);
			}
			return;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(mode[v]==0)
			{
				mode[2*v] = mode[2*v+1] = 0;
				value[2*v] = std::make_pair(-1,-1);
				value[2*v+1] = std::make_pair(-1,-1);
				mode[v] = 2;
			}
			else if(mode[v]==1)
			{
				mode[2*v] = mode[2*v+1] = 1;
				value[2*v] = on[2*v];
				value[2*v+1] = on[2*v+1];
				mode[v] = 2;
			}
			
			doQuery(L,R,val,l,h,2*v);
			doQuery(L,R,val,h+1,r,2*v+1);
			update(v);
		}
	}
	
	std::pair<int,int> get()
	{
		return value[1];
	}
}T;

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	init(1,0,1);
	next[1][0] = std::make_pair(1,-1);
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			next[i][j].first = next[next[i][j-1].first][j-1].first;
			int s = next[i][j-1].second;
			int t = next[next[i][j-1].first][j-1].second;
			next[i][j].second = (s>t?s:t);
		}
	}
	
	T.init();
	
	while(b--)
	{
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			T.doQuery(d,e,1);
		}
		else if(c==2)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			T.doQuery(d,e,0);
		}
		else
		{
			int d;
			scanf("%d",&d);
			std::pair<int,int> P = T.get();
			
			if(P.first==-1) printf("-1\n");
			else
			{
				int M = P.second;
				int L = LCA(P.first,d);
				int temp;
				temp = getMax(d,L);
				M = M>temp?M:temp;
				temp = getMax(P.first,L);
				M = M>temp?M:temp;
				printf("%d\n",M);
			}
		}
	}
}