#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int x[1000000],y[1000000];
  for(int i=0;i<n;i++){
    scanf("%d%d",x+i,y+i);
  }
  static pair<pair<int,int>,int> P[1000000];
  for(int i=0;i<n;i++){
    int c=y[i]/1000;
    P[i]=make_pair(make_pair(c,(c%2==0?1:-1)*x[i]),i);
  }
  sort(P,P+n);
  for(int i=0;i<n;i++){
    printf("%d%c",P[i].second+1,i<n-1?' ':'\n');
  }
  return 0;
}