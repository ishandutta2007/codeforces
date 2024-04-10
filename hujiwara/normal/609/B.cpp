#include <cstdio>

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int a[10]={0};
  for(int i=0;i<n;i++){
    int g;
    scanf("%d",&g);
    a[g-1]++;
  }
  int C=0;
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      C+=a[i]*a[j];
    }
  }
  printf("%d\n",C);
  return 0;
}