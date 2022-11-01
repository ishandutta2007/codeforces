#include <bits/stdc++.h>
using namespace std;

const double EPS=1e-6;

int main()
{
  int n;
  scanf("%d",&n);
  int s=1,M=n+1;
  for(int t=1;t<=n;t++){
    int m=t+(n+t-1)/t;
    if(M>m){
      M=m;
      s=t;
    }
  }
  pair<pair<int,int>, int> P[100010];
  for(int i=0;i<n;i++){
    P[i]=make_pair(make_pair(i%s,-i/s),i);
  }
  sort(P,P+n);
  for(int i=0;i<n;i++){
    printf("%d%c",P[i].second+1,i==n-1?'\n':' ');
  }
  return 0;
}