#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;

int main()
{
  int n;
  scanf("%d",&n);
  static char s[(1<<20)+10];
  scanf("%s",s);
  static int f[1<<20];
  for(int i=0;i<1<<n;i++){
    f[i]=(s[i]=='1');
  }
  static long long F[2][1<<20];
  bool b=0;
  for(int i=0;i<1<<n;i++){
    F[b][i]=f[i];
  }
  for(int t=0;t<n;t++){
    for(int i=0;i<1<<n;i++){
      F[!b][i]=(2ll*F[b][i]+F[b][i^(1<<t)])%mod;
      //printf("%d %lld\n",i,F[!b][i]);
    }
    b=!b;
  }
  long long ans=0ll;
  for(int i=0;i<1<<n;i++){
    if(f[i]){
      ans+=F[b][i];
      ans%=mod;
    }
  }
  printf("%lld\n",(3ll*ans)%mod);
  return 0;
}