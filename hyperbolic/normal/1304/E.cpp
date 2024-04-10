#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
int height[300010];
int next[300010][30];
void func(int k, int prev, int h)
{
	height[k] = h;
	next[k][0] = prev;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1);
	}
}

int dist(int s, int t)
{
	int ans = 0;
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		ans += k;
		for(int i=20;i>=0;i--) if(k>=(1<<i)) s = next[s][i], k-=(1<<i);
	}
	else if(height[s]<height[t])
	{
		int k = height[t]-height[s];
		ans += k;
		for(int i=20;i>=0;i--) if(k>=(1<<i)) t = next[t][i], k-=(1<<i);
	}
	
	for(int i=20;i>=0;i--)
	{
		if(next[s][i]!=next[t][i])
		{
			s = next[s][i], t = next[t][i];
			ans += 2*(1<<i);
		}
	}
	if(s==t) return ans;
	else return ans+2;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	func(1,0,1);
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e,f,g;
		scanf("%d%d%d%d%d",&c,&d,&e,&f,&g);
		int s1 = dist(e,f);
		if(g>=s1 && (g-s1)%2==0) printf("YES\n");
		else
		{
			int s2 = dist(e,c)+dist(d,f)+1;
			int s3 = dist(e,d)+dist(c,f)+1;
			if(g>=s2 && (g-s2)%2==0) printf("YES\n");
			else if(g>=s3 && (g-s3)%2==0) printf("YES\n");
			else printf("NO\n");
		}
	}
}