// Hydro submission #630873c07efc586f4bd26e1a@1661498305277
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,f[200000+5],ff[200000+5],fff[200000+5],a,b;
int main()
{
  scanf("%d%d%d",&n,&k,&m);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&a,&b);
    ff[a]++,ff[b+1]--;
  }
  for(int i=1;i<=200000;i++)
  {
    f[i]=f[i-1]+ff[i];
    if(f[i]>=k)fff[i]=fff[i-1]+1;
      else fff[i]=fff[i-1];
  }
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&a,&b);
    printf("%d\n",fff[b]-fff[a-1]);
  }
  return 0;
}