#include <stdio.h>
#include <vector>

int next[2010];
char x[1010][1010];
int find(int k)
{
	if(next[k]==k) return k;
	else return next[k] = find(next[k]);
}

int check[2010];
std::vector<int> V[2010];
int func(int k)
{
	if(check[k]) return check[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		int t = func(V[k][i])+1;
		ans = ans>t?ans:t;
	}
	return check[k] = ans;
}

int check2[2010];
int isCycle(int k)
{
	if(check2[k]==2) return 0;
	check2[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check2[V[k][i]]==1) return 1;
		if(check2[V[k][i]]==0)
		{
			int t = isCycle(V[k][i]);
			if(t==1) return 1;
		}
	}
	check2[k] = 2;
	return 0;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a+b;i++) next[i] = i;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='=')
			{
				int s = find(i);
				int t = find(j+a);
				if(s!=t) next[s] = t;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='>')
			{
				int s = find(i);
				int t = find(j+a);
				if(s==t)
				{
					printf("No");
					return 0;
				}
				V[s].push_back(t);
			}
			if(x[i][j]=='<')
			{
				int s = find(i);
				int t = find(j+a);
				if(s==t)
				{
					printf("No");
					return 0;
				}
				V[t].push_back(s);
			}
		}
	}
	
	for(int i=1;i<=a+b;i++)
	{
		if(isCycle(i))
		{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes\n");
	for(int i=1;i<=a;i++) printf("%d ",func(find(i)));
	printf("\n");
	for(int j=1;j<=b;j++) printf("%d ",func(find(j+a)));
}