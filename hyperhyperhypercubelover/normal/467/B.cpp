#include <cstdio>
int a,b,c,i,j,x[1003],y,ans,s;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  for(i=0;i<b;i++)
  {
    scanf("%d",&x[i]);
  }
  scanf("%d",&y);
  for(i=0;i<b;i++)
  {
    s=0;
    for(j=0;j<a;j++)
    {
      if(y/(1<<j)%2!=x[i]/(1<<j)%2)
      {
        s++;
      }
    }
    if(s<=c)ans++;
  }
  printf("%d",ans);
}