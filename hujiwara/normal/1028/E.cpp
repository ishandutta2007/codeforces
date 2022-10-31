#include <bits/stdc++.h>
using namespace std;
const int MN=200000;

int main()
{
  int n;
  scanf("%d",&n);
  static int b[MN];
  for(int i=0;i<n;i++){
    scanf("%d",b+i);
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(b[i]!=b[(i+1)%n]){
      F=1;
      break;
    }
  }
  if(!F){
    if(b[0]==0){
      puts("YES");
      for(int i=0;i<n;i++){
	printf("%d%c",1,i==n-1?'\n':' ');
      }
    }
    else{
      puts("NO");
    }
    return 0;
  }
  static long long a[MN];
  for(int i=0;i<n;i++){
    if(b[i]<b[(i+1)%n]){
      a[(i+1)%n]=b[(i+1)%n];
      int j=i;
      while(b[(j+n-1)%n]>=b[j]){
	a[j]=b[j]+(b[(j+n-1)%n]/a[(j+1)%n]+1)*a[(j+1)%n];
	j=(j+n-1)%n;
      }
    }
  }
  puts("YES");
  for(int i=0;i<n;i++){
    printf("%lld%c",a[i],i==n-1?'\n':' ');
  }
  return 0;
}