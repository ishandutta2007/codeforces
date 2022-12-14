#include <stdio.h>
#include <vector>

struct str{
	long long int score1;
	long long int score2;
	int limit;
};

long long int x[200010];
std::vector<int> V[200010];
int height[200010],back[200010];
int root;

str func(int k, int prev)
{
	str ans;
	ans.score1 = 0;
	ans.score2 = 0;
	ans.limit = back[k];
	for(int i=0;i<V[k].size();i++)
	{
		if(height[V[k][i]]!=height[k]+1) continue;
		str A = func(V[k][i],k);
		if(height[A.limit]>height[k])
		{
			ans.score2 = ans.score2>A.score1+A.score2?ans.score2:A.score1+A.score2;
		}
		else
		{
			ans.score1 += A.score1;
			ans.score2 = ans.score2>A.score2?ans.score2:A.score2;
			ans.limit = height[ans.limit]<height[A.limit]?ans.limit:A.limit;
		}
	}
	ans.score1 += x[k];
	if(height[ans.limit]<height[k]) ans.limit = root;
	return ans;
}

void init(int k, int prev, int h)
{
	height[k] = h;
	back[k] = k;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(height[V[k][i]]>0)
		{
			if(height[V[k][i]]<height[back[k]]) back[k] = V[k][i];
		}
		else init(V[k][i],k,h+1);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	scanf("%d",&root);
	init(root,0,1);
	str A = func(root,0);
	printf("%lld",A.score1+A.score2);
}