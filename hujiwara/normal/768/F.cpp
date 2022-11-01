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
long long iv(long long a){return pw(a,mod-2);}

void prev(int N,long long *inv,long long *F,long long *iF)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=iF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    iF[i]=iF[i-1]*inv[i]%mod;
  }
}
long long inv[100010],F[100010],iF[100010];

long long C(int i,int j)
{
  return i<0||j<0||i<j?0ll:F[i]*iF[j]%mod*iF[i-j]%mod;
}

int main()
{
  int f,w,h;
  scanf("%d%d%d",&f,&w,&h);
  if(f==0){
    printf("%d\n",h<w?1:0);
    return 0;
  }
  if(w==0){
    printf("1\n");
    return 0;
  }
  h++;
  prev(100010,inv,F,iF);
  long long P=0,Q=0;
  for(int i=1;i<=f&&i*h<=w;i++){
    P+=C(f-1,i-1)*C(w-1-(h-1)*i,i-1)%mod*2ll%mod;
    P%=mod;
    if(i+1<=f){
      P+=C(f-1,i)*C(w-1-(h-1)*i,i-1)%mod;
      P%=mod;
    }
    if((i+1)*h<=w){
      P+=C(f-1,i-1)*C(w-1-(h-1)*(i+1),i)%mod;
      P%=mod;
    }
  }
  for(int i=1;i<=f&&i<=w;i++){
    Q+=C(f-1,i-1)*C(w-1,i-1)%mod*2ll%mod;
    Q%=mod;
    if(i+1<=f){
      Q+=C(f-1,i)*C(w-1,i-1)%mod;
      Q%=mod;
    }
    if(i+1<=w){
      Q+=C(f-1,i-1)*C(w-1,i)%mod;
      Q%=mod;
    }
  }
  printf("%lld\n",P*iv(Q)%mod);
  return 0;
}