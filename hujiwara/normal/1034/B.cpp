#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n,m;
  scanf("%lld%lld",&n,&m);
  if(n>m){
    swap(n,m);
  }
  long long ans;
  if(n==1){
    ans=(m/6)*6+(m%6==4?2:m%6==5?4:0);
  }
  else if(n==2){
    if(m==2){
      ans=0;
    }
    else if(m==3){
      ans=4;
    }
    else if(m==7){
      ans=12;
    }
    else{
      ans=2*m;
    }
  }
  else{
    ans=n*m/2*2;
  }
  printf("%lld\n",ans);
  return 0;
}