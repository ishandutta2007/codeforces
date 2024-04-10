#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long L;
  scanf("%d%lld",&n,&L);
  long long c[50];
  for(int i=0;i<n;i++){
    scanf("%lld",c+i);
  }
  for(int i=1;i<n;i++){
    c[i]=min(c[i],2*c[i-1]);
  }
  for(int i=n-2;i>=0;i--){
    c[i]=min(c[i],c[i+1]);
  }
  long long cur=(L/(1ll<<(n-1)))*c[n-1];
  L%=(1ll<<(n-1));
  long long ans=cur+(L>0?c[n-1]:0);
  for(int i=n-2;i>=0;i--){
    if(L>=(1ll<<i)){
      L-=1ll<<i;
      cur+=c[i];
    }
    ans=min(ans,cur+(L>0?c[i]:0));
  }
  printf("%lld\n",ans);
  return 0;
}