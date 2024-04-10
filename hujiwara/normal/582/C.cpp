#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}

int main()
{
  int n;
  scanf("%d",&n);
  static int a[200000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  static vector<int> G[200001];
  for(int i=1;i<n;i++){
    G[gcd(n,i)].push_back(i);
  }
  long long ans=0ll;
  for(int g=1;g<n;g++){
    if(n%g!=0){
      continue;
    }
    vector<int> M(g,0);
    for(int i=0;i<n;i++){
      M[i%g]=max(M[i%g],a[i]);
    }
    int t=0;
    while(t<n&&M[t%g]==a[t]){
      t++;
    }
    for(int i=n-1;i>=0;i--){
      if(M[i%g]==a[i]){
	t=min(t+1,n);
      }
      else{
	t=0;
      }
      //printf("%d %d %d %d\n",g,i,t,G[g].size());
      ans+=upper_bound(G[g].begin(),G[g].end(),t)-G[g].begin();
    }
  }
  printf("%lld\n",ans);
  return 0;
}