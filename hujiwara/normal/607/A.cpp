#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static pair<int,int> P[100000];
  for(int i=0;i<n;i++){
    scanf("%d%d",&(P[i].first),&(P[i].second));
  }
  sort(P,P+n);
  int ans=0;
  static int g[100000];
  for(int i=0;i<n;i++){
    int j=lower_bound(P,P+n,make_pair(P[i].first-P[i].second,0))-P;
    g[i]=1+(j==0?0:g[j-1]);
    ans=max(ans,g[i]);
  }
  printf("%d\n",n-ans);
  return 0;
}