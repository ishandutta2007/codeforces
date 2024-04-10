#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static bool E[100010]={0};
  for(int i=2;i<=n+1;i++){
    if(!E[i]){
      for(int j=2*i;j<=n+1;j+=i){
	E[j]=1;
      }
    }
  }
  printf("%d\n",n<=2?1:2);
  for(int i=0;i<n;i++){
    printf("%d%c",E[i+2]?2:1,i<n-1?' ':'\n');
  }
  return 0;
}