#include <stdio.h>
#include <vector>

int check[100010],size[100010];
int parent[100010];
std::vector<int> V[100010];

int func(int k, int prev)
{
	if(size[k]) return size[k];
	parent[k] = prev;
	
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += func(V[k][i],k);
	}
	return size[k] = ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) size[i] = check[i] = 0;
		for(int i=1;i<=a;i++) parent[i] = 0;
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		int root, left;
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==1)
			{
				root = V[i][0];
				left = i;
				break;
			}
		}
		printf("%d %d\n",root,left);
		func(root,left);
		for(int i=1;i<=a;i++)
		{
			if(i==left) continue;
			int S = a-1-size[i];
			for(int j=0;j<V[i].size();j++)
			{
				if(V[i][j]==parent[i]) continue;
				S = S>size[V[i][j]]?S:size[V[i][j]];
			}
			check[i] = S;
		}
		
		int min = 12345678;
		for(int i=1;i<=a;i++)
		{
			if(i==left) continue;
			min = min<check[i]?min:check[i];
		}
		for(int i=1;i<=a;i++)
		{
			if(i==left) continue;
			if(check[i]==min)
			{
				printf("%d %d\n",left,i);
				break;
			}
		}
	}
}