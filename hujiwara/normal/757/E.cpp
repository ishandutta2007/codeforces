#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long inv(long long a){return pw(a,mod-2);}

int main()
{
  const int N=1100000;
  static int E[N];
  for(int i=0;i<N;i++){
    E[i]=i;
  }
  for(int i=2;i<N;i++){
    if(E[i]==i){
      for(int j=i+i;j<N;j+=i){
	E[j]=i;
      }
    }
  }
  static long long F[N],inv[N],IF[N];
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=IF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    IF[i]=IF[i-1]*inv[i]%mod;
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int r,n;
    scanf("%d%d",&r,&n);
    long long ans=1ll;
    while(n>1){
      int P=E[n],R=0;
      while(n%P==0){
	n/=P;
	R++;
      }
      long long S=0;
      if(r==0){
	S=2;
      }
      else{
	S=2*F[R+r]%mod*IF[R]%mod*IF[r]%mod;
	mn(S,F[R+r-1]*IF[R]%mod*IF[r-1]%mod);
      }
      //printf("%d %lld\n",R,S);
      ml(ans,S);
    }
    printf("%lld\n",ans);
  }
  return 0;
}