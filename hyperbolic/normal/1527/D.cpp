#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int height[200010];
int next[200010][30];

void init(int k, int prev, int h)
{
	height[k] = h;
	next[k][0] = prev;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,h+1);
	}
}

int size[200010];
int getSize(int k, int prev)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}

int LCA(int a, int b)
{
	if(height[a]>height[b])
	{
		int c = height[a]-height[b];
		for(int i=20;i>=0;i--)
		{
			if(c>=(1<<i))
			{
				a = next[a][i];
				c -= (1<<i);
			}
		}
	}
	if(height[a]<height[b])
	{
		int c = height[b]-height[a];
		for(int i=20;i>=0;i--)
		{
			if(c>=(1<<i))
			{
				b = next[b][i];
				c -= (1<<i);
			}
		}
	}
	
	for(int i=20;i>=0;i--)
	{
		if(next[a][i]!=next[b][i])
		{
			a = next[a][i];
			b = next[b][i];
		}
	}
	if(a==b) return a;
	else return next[a][0];
}

long long int ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<a;i++) V[i].clear();
		for(int i=0;i<a;i++) size[i] = 0;
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		init(0,-1,1);
		for(int i=1;i<=20;i++) for(int j=0;j<a;j++) next[j][i] = next[next[j][i-1]][i-1];
		ans[0] = (long long int)a*(a-1)/2;
		for(int i=1;i<=a+1;i++) ans[i] = 0;
		
		long long int s1 = 0, s2 = 0;
		for(int i=0;i<V[0].size();i++)
		{
			long long int t = getSize(V[0][i],0);
			s1 += t, s2 += t*t;
		}
		ans[1] = (s1*s1-s2)/2 + (a-1);
		
		s1 = 1, s2 = 1;
		for(int i=0;i<V[0].size();i++)
		{
			if(LCA(V[0][i],1)==V[0][i]) continue;
			s1 += getSize(V[0][i],0);
		}
		s2 = getSize(1,next[1][0]);
		ans[2] = s1*s2;
		
		int p1 = 0, p2 = 1;
		for(int i=2;i<a;i++)
		{
			if(LCA(i,p2)==p2)
			{
				p2 = i;
				s2 = getSize(i,next[i][0]);
			}
			else if(LCA(i,p2)==i);
			else if(LCA(i,p1)==p1)
			{
				p1 = i;
				s1 = getSize(i,next[i][0]);
			}
			else if(LCA(i,p1)==i);
			else break;
			
			if(LCA(p1,p2)!=0) break;
			ans[i+1] = s1*s2;
		}
		
		for(int i=0;i<=a;i++) printf("%lld ",ans[i]-ans[i+1]);
		printf("\n");
	}
}