#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  static int f[200000],r[200000];
  for(int i=0;i<n;i++){
    scanf("%d",f+i);
    f[i]--;
    r[f[i]]=i;
  }
  long long C=0;
  for(int i=0;i<n-1;i++){
    C+=(r[i]<r[i+1]?r[i+1]-r[i]:r[i]-r[i+1]);
  }
  printf("%I64d\n",C);
  return 0;
}