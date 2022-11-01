#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  bool F=1;
  for(int i=2;(long long)i*i<=n;i++){
    if(n%i==0){
      F=0;
      break;
    }
  }
  bool F2=1;
  for(int i=2;(long long)i*i<=n-2;i++){
    if((n-2)%i==0){
      F2=0;
      break;
    }
  }
  printf("%d\n",F?1:n%2==0||F2?2:3);
  return 0;
}