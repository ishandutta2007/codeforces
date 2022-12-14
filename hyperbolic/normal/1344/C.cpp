#include <stdio.h>
#include <vector>
 
std::vector<int> V[200010],V1[200010],V2[200010];
 
int check[200010],check1[200010],check2[200010];
void func(int k, int type);
void func1(int k)
{
	check[k] = 1;
	check1[k] = 1;
	for(int i=0;i<V1[k].size();i++) if(check1[V1[k][i]]==0) func1(V1[k][i]);
}
void func2(int k)
{
	check[k] = 1;
	check2[k] = 1;
	for(int i=0;i<V2[k].size();i++) if(check2[V2[k][i]]==0) func2(V2[k][i]);
}
 
void func(int k,int type)
{
	check[k] = type;
	check1[k] = check2[k] = 1;
	for(int i=0;i<V1[k].size();i++) if(check1[V1[k][i]]==0) func1(V1[k][i]);
	for(int i=0;i<V2[k].size();i++) if(check2[V2[k][i]]==0) func2(V2[k][i]);
}
 
int control = 0;
int dfs[200010];
 
void DFS(int k)
{
	if(control) return;
	dfs[k] = 1;
	for(int i=0;i<V1[k].size();i++)
	{
		if(dfs[V1[k][i]]==1)
		{
			control = 1;
			return;
		}
		if(dfs[V1[k][i]]==0) DFS(V1[k][i]);
	}
	dfs[k] = 2;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
		V1[c].push_back(d);
		V2[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) if(dfs[i]==0) DFS(i);
	if(control)
	{
		printf("-1");
		return 0;
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			ans++;
			func(i,1);
			u:;
		}
		else func(i,2);
	}
	printf("%d\n",ans);
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) printf("A");
		else if(check[i]==2) printf("E");
		else
		{
			while(1);
		}
	}
}