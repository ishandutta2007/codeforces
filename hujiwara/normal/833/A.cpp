#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  scanf("%d",&T);
  while(T--){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    bool F=1;
    if(a*a%b!=0||b*b%a!=0){
      F=0;
    }
    else{
      long long c=a*a/b;
      long long c3=(long long)(pow((long double)c,(long double)1./3.)+0.5);
      if(c3*c3*c3!=c){
	F=0;
      }
    }
    puts(F?"Yes":"No");
  }
  return 0;
}