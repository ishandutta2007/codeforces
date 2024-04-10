#include <stdio.h>
#include <vector>
std::vector<int> V[200010];
int x[200010];
int check[200010];
int up[200010];
int t = 1;
void func(int k,int color)
{
	check[k] = color;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==color)
		{
			x[t++] = k;
			continue;
		}
		else if(check[V[k][i]]!=0) continue;
		func(V[k][i],color);
	}
}
int main()
{
	int a,b,c=1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		up[i] = b;
		V[b].push_back(i);
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			func(i,c);
			c++;
		}
	}
	for(int i=1;i<t;i++)
	{
		if(up[x[i]]==x[i])
		{
			for(int j=1;j<t;j++)
			{
				if(i==j) continue;
				up[x[j]] = x[i];
			}
			printf("%d\n",t-2);
			for(int j=1;j<=a;j++) printf("%d ",up[j]);
			return 0;
		}
	}
	for(int j=2;j<t;j++) up[x[j]] = x[1];
	up[x[1]] = x[1];
	printf("%d\n",t-1);
	for(int j=1;j<=a;j++) printf("%d ",up[j]);
}