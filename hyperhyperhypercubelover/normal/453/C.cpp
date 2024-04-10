#include<cstdio>
#include<vector>

std::vector<int> graph[100001];
int a[100001];
int v[100001];

int r[500000];
int rn;

void dfs(int x)
{
  int i;
  v[x]=1;
  r[rn++]=x;
  a[x]=!a[x];
  for(i=0;i<graph[x].size();i++)if(!v[graph[x][i]])
  {
    dfs(graph[x][i]);
    r[rn++]=x;
    a[x]=!a[x];
    if(a[graph[x][i]])
    {
      r[rn++]=graph[x][i];
      a[graph[x][i]]=!a[graph[x][i]];
      r[rn++]=x;
      a[x]=!a[x];
    }
  }
}

int main()
{
  int s,e;
  int i,n,m;
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++)
  {
    scanf("%d%d",&s,&e);
    graph[s].push_back(e);
    graph[e].push_back(s);
  }
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=n;i++)if(a[i])break;
  if(i>n)
  {
    puts("0");
    return 0;
  }
  dfs(i);
  if(a[i]&&!graph[i].empty())
  {
    r[rn++]=graph[i][0];
    a[i]=!a[i];
    r[rn++]=i;
    r[rn++]=graph[i][0];
  }
  for(i=1;i<=n;i++)if(a[i])
  {
    puts("-1");
    return 0;
  }
  printf("%d\n",rn);
  for(i=0;i<rn;i++)printf("%d ",r[i]);
}