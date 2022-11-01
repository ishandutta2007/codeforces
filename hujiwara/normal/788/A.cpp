#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static long long a[100000];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  long long s=abs(a[0]-a[1]);
  long long mx=s;
  for(int i=1;i+1<n;i++){
    if(i%2==0){
      s=max(s,0ll);
    }
    s+=(i%2==0?1:-1)*abs(a[i]-a[i+1]);
    mx=max(mx,s);
  }
  if(n>2){
    s=abs(a[1]-a[2]);
    mx=max(mx,s);
    for(int i=2;i+1<n;i++){
      if(i%2==1){
	s=max(s,0ll);
      }
      s+=(i%2==1?1:-1)*abs(a[i]-a[i+1]);
      mx=max(mx,s);
    }
  }
  printf("%lld\n",mx);
  return 0;
}