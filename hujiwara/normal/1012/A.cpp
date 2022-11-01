#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<long long> a(2*n);
  for(int i=0;i<2*n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a.begin(),a.end());
  long long ans=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
  for(int i=1;i<n;i++){
    ans=min(ans,(a[2*n-1]-a[0])*(a[n+i-1]-a[i]));
  }
  printf("%lld\n",ans);
  return 0;
}