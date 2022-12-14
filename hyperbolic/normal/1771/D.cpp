#include <stdio.h>
#include <vector>

std::vector<int> V[2010];
int height[2010],next[2010][20];
void init(int k, int p, int h)
{
	height[k] = h;
	next[k][0] = p;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		init(V[k][i],k,h+1);
	}
}

int dist(int s, int t)
{
	int ans = 0;
	if(height[s]<height[t])
	{
		int val = height[t]-height[s];
		ans += val;
		for(int j=11;j>=0;j--)
		{
			if(val>=(1<<j))
			{
				val -= (1<<j);
				t = next[t][j];
			}
		}
	}
	if(height[s]>height[t])
	{
		int val = height[s]-height[t];
		ans += val;
		for(int j=11;j>=0;j--)
		{
			if(val>=(1<<j))
			{
				val -= (1<<j);
				s = next[s][j];
			}
		}
	}
	for(int j=11;j>=0;j--)
	{
		if(next[s][j]!=next[t][j])
		{
			ans += 2*(1<<j);
			s = next[s][j], t = next[t][j];
		}
	}
	if(s==t) return ans;
	else return ans+2;
}

int check[2010][2010],dist2[2010][2010];
char x[2010];
int func(int s, int t)
{
	if(s>t) return func(t,s);
	if(check[s][t]!=-1) return check[s][t];
	
	int d = dist(s,t);
	int ans = 0;
	std::vector<int> W1, W2;
	for(int i=0;i<V[s].size();i++) if(dist2[V[s][i]][t]>d) W1.push_back(V[s][i]);
	for(int i=0;i<V[t].size();i++) if(dist2[s][V[t][i]]>d) W2.push_back(V[t][i]);
	for(int i=0;i<W1.size();i++)
	{
		int val = func(W1[i],t);
		ans = ans>val?ans:val;
	}
	for(int i=0;i<W2.size();i++)
	{
		int val = func(s,W2[i]);
		ans = ans>val?ans:val;
	}
	if(x[s]==x[t])
	{
		ans = ans>2?ans:2;
		for(int i=0;i<W1.size();i++)
		{
			for(int j=0;j<W2.size();j++)
			{
				int val = 2 + func(W1[i],W2[j]);
				ans = ans>val?ans:val;
			}
		}
	}
	return check[s][t] = ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = -1;
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		init(1,0,1);
		for(int j=1;j<=11;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
		
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) dist2[i][j] = dist(i,j);
		
		int ans = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				int val;
				if(dist(i,j)==1) val = func(i,j);
				else val = 1+func(i,j);
				ans = ans>val?ans:val;
			}
		}
		printf("%d\n",ans);
	}
}