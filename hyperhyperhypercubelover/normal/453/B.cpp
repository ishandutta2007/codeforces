#include<cstdio>
#include<vector>
#include<algorithm>

#define abs(x) ((x)<0?-(x):(x))

std::pair<int,int> a[100];
int n;

int d[100];
int t[100];
int v[100];

int r[100];
int min=2e9;

int pre[100][100];
int pren[100];

int isprime(int x)
{
  if(x==1)return 0;
  int i;
  for(i=2;i<x;i++)if(x%i==0)return 0;
  return 1;
}

void dfs(int x,int y)
{
  int i,j,temp;
  if(x>20)
  {
    for(i=0;i<20;i++)t[i]=d[i];
    for(i=20;i<n;i++)t[i]=1;
    temp=0;
    for(i=0;i<n;i++)temp+=abs(t[n-i-1]-a[i].first);
    if(temp<min)
    {
      min=temp;
      for(i=0;i<n;i++)r[a[i].second]=t[n-i-1];
    }
    return;
  }
  for(i=y;i>=1;i--)
  {
    for(j=0;j<pren[i];j++)if(v[pre[i][j]])break;
    if(j==pren[i]&&!v[i])
    {
      for(j=0;j<pren[i];j++)v[pre[i][j]]=1;
      d[x]=i;
      dfs(x+1,i);
      for(j=0;j<pren[i];j++)v[pre[i][j]]=0;
    }
  }
}

int main()
{
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i].first);
    a[i].second=i;
  }
  for(i=1;i<100;i++)for(j=2;j<=i;j++)if(i%j==0&&isprime(j))pre[i][pren[i]++]=j;
  std::sort(a,a+n);
  dfs(0,60);
  for(i=0;i<n;i++)printf("%d ",r[i]);
}