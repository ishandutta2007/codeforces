#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  int a[1000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<a[i];j++){
      putchar('P');
      if(i==n-1){
	putchar('L');
	putchar('R');
      }
      else{
	putchar('R');
	putchar('L');
      }
    }
    if(i<n-1){
      putchar('R');
    }
  }
  putchar('\n');
  return 0;
}