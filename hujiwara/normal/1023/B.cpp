#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n,k;
  scanf("%lld%lld",&n,&k);
  long long ans=max(min(n,(k-1)/2)-max(1ll,k-n)+1,0ll);
  printf("%lld\n",ans);
  return 0;
}