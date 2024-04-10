#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static char s[100001];
  scanf("%s",s);
  long long ans=0ll;
  for(int i=0;i<n;){
    int t=1;
    while(i+t<n&&s[i+t]==s[i]){
      t++;
    }
    ans+=n*(m-1);
    i+=t;
  }
  for(int i=0;i+1<n;){
    int t=2;
    while(i+t<n&&s[i+t]==s[i+t%2]){
      t++;
    }
    if(s[i]!=s[i+1]){
      ans-=(long long)t*(t-1)/2;
    }
    i+=t-1;
  }
  printf("%lld\n",ans);
  return 0;
}