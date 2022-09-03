#include<cstdio>
#include<vector>

std::vector<int> graph[100001];
int v[100001];

void dfs(int x)
{
	int i;
	for(i=0;i<graph[x].size();i++)if(!v[graph[x][i]])
	{
		v[graph[x][i]]=v[x]+1;
        dfs(graph[x][i]);
	}
}

int main()
{
	double res=0;
	int a,b;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	v[1]=1;
	dfs(1);
	for(i=1;i<=n;i++)res+=1./v[i];
	printf("%.8lf",res);
}