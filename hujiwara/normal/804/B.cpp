#include <bits/stdc++.h>
using namespace std;

int main()
{
  static char s[1000010];
  scanf("%s",s);
  int n=strlen(s);
  const long long mod=1000000007ll;
  long long B=0,ans=0;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='b'){
      B++;
      B%=mod;
    }
    else{
      ans+=B;
      ans%=mod;
      B*=2ll;
      B%=mod;
    }
  }
  printf("%lld\n",ans);
  return 0;
}