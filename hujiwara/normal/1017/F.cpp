#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  static unsigned long long E[100000010/64+1]={0};
  long long A,B,C,D;
  scanf("%d%lld%lld%lld%lld",&n,&A,&B,&C,&D);
  long long ans=0ll,mod=1ull<<32;
  for(int i=2;i<=n;i++){
    if(i!=2&&i!=3&&!((i%6==1||i%6==5)&&!((E[(i/3)/64]>>(i/3%64))&1)))continue;
    if(i!=2&&i!=3){
      for(int j=2*i;j<=n;j+=i){
	if(j%6==1||j%6==5){
	  E[j/3/64]|=(1ull<<(j/3%64));
	}
      }
    }
    long long a=0;
    long long p=i;
    while(p<=n){
      a+=n/p;
      p*=i;
    }
    ans+=(A*i%mod*i%mod*i+B*i%mod*i+C*i+D)%mod*a;
    ans%=mod;
  }
  printf("%lld\n",ans);
  return 0;
}