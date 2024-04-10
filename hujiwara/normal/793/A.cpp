#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long k;
  scanf("%d%lld",&n,&k);
  static long long a[100000];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  long long mn=a[0];
  for(int i=1;i<n;i++){
    mn=min(mn,a[i]);
  }
  long long ans=0;
  bool F=0;
  for(int i=0;i<n;i++){
    if((a[i]-mn)%k==0){
      ans+=(a[i]-mn)/k;
    }
    else{
      F=1;
    }
  }
  printf("%lld\n",F?-1:ans);
  return 0;
}