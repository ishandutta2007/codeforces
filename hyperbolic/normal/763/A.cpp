#include <stdio.h>
#include <vector>

int x[100010];
std::vector<int> V[100010];

int func(int k, int prev)
{
	int col = x[k];
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(func(V[k][i],k)!=col) return -1;
	}
	return col;
}
int func2(int k)
{
	for(int i=0;i<V[k].size();i++)
	{
		if(func(V[k][i],k)==-1) return 0;
	}
	return 1;
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
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(x[V[i][j]]!=x[i])
			{
				int s = i, t = V[i][j];
				if(func2(s)) printf("YES\n%d",s);
				else if(func2(t)) printf("YES\n%d",t);
				else printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n1");
}