#include<cstdio>

int a[101];
int b[101];

int main()
{
  int i,j,n,m,t;
  scanf("%d%d",&n,&m);
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&i);
    a[i]=1;
  }
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&i);
    b[i]=1;
  }
  for(i=0;i<2*n*m;i++)
  {
    t=a[i%n]||b[i%m];
    a[i%n]=b[i%m]=t;
    t=0;
    for(j=0;j<n;j++)if(a[j])t++;
    for(j=0;j<m;j++)if(b[j])t++;
    if(t==n+m)break;
  }
  if(i<2*n*m)puts("Yes");
  else puts("No");
}