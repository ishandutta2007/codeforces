#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  int c=-1,d;
  for(int k=0;a*k<=n;k++){
    if((n-a*k)%b==0){
      c=k;
      d=(n-a*k)/b;
      break;
    }
  }
  if(c==-1){
    puts("-1");
  }
  else{
    for(int i=0;i<c;i++){
      for(int j=0;j<a;j++){
	printf("%d ",1+i*a+(j+1)%a);
      }
    }
    for(int i=0;i<d;i++){
      for(int j=0;j<b;j++){
	printf("%d ",1+a*c+i*b+(j+1)%b);
      }
    }
    puts("");
  }
  return 0;
}