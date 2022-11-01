#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static pair<int,int> P1[200000],P2[2000000];
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    P1[i]=make_pair(x,y);
    P2[i]=make_pair(y,x);
  }
  sort(P1,P1+n);
  sort(P2,P2+n);
  long long ans=0;
  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&P1[i+t].first==P1[i].first){
      t++;
    }
    ans+=(long long)t*(t-1)/2;
    i+=t;
  }
  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&P2[i+t].first==P2[i].first){
      t++;
    }
    ans+=(long long)t*(t-1)/2;
    i+=t;
  }

  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&P1[i+t]==P1[i]){
      t++;
    }
    ans-=(long long)t*(t-1)/2;
    i+=t;
  }
  printf("%lld\n",ans);
  return 0;
}