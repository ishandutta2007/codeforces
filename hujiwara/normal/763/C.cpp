#include <bits/stdc++.h>
using namespace std;

long long sq(long long a,long long mod){return a*a%mod;}
long long pw(long long a,long long n,long long mod)
{
  return n==0?1ll:sq(pw(a,n/2,mod),mod)*(n%2==1?a:1ll)%mod;
}
long long inv(long long a,long long mod){return pw(a,mod-2,mod);}


const int MN=100000;

int ct(int n,long long m,long long *a,int t)
{
  long long D[MN];
  for(int i=0;i<n;i++){
    D[i]=(a[i]+m-a[t])%m;
  }
  sort(D,D+n);
  int c=0;
  for(int i=0;i<n;i++){
    long long g=(m-D[i])%m;
    int j=lower_bound(D,D+n,g)-D;
    if(j<n&&D[j]==g){
      c++;
    }
  }
  return c;
}

bool X=0;

bool check(int n,long long m,long long *a,int k0,int k1)
{
  if(k0==k1){
    return 0;
  }
  long long A[MN];
  for(int i=0;i<n;i++){
    A[i]=a[i];
  }
  sort(A,A+n);
  long long d=(a[1]+m-a[0])%m*inv((k1+m-k0)%m,m)%m;
  long long b=(a[0]+m-d*k0%m)%m;
  for(int i=0;i<n;i++){
    long long g=(b+d*i%m)%m;
    int j=lower_bound(A,A+n,g)-A;
    if(j>=n||A[j]!=g){
      return 0;
    }
  }
  if(!X){
    printf("%lld %lld\n",b,d);
  }
  else{
    printf("%lld %lld\n",(b+d*n%m)%m,d);
  }
  return 1;
}

int main()
{
  long long m;
  int n;
  scanf("%lld%d",&m,&n);
  static long long a[MN];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  if(n==1){
    printf("%lld 1\n",a[0]);
    return 0;
  }
  if(n==m){
    printf("0 1\n");
    return 0;
  }
  if(n*2>m){
    static bool B[2*MN]={0};
    for(int i=0;i<n;i++){
      B[a[i]]=1;
    }
    int t=0;
    for(int i=0;i<m;i++){
      if(!B[i]){
	a[t]=i;
	t++;
      }
    }
    n=t;
    X=1;
    if(n==1){
      printf("%lld 1\n",(a[0]+1)%m);
      return 0;
    }
  }
  int c0=ct(n,m,a,0),c1=ct(n,m,a,1);
  //printf("%d %d\n",c0,c1);
  bool F=check(n,m,a,n-1-(c0-1)/2,n-1-(c1-1)/2);
  if(!F){
    F=check(n,m,a,n-1-(c0-1)/2,(c1-1)/2);
  }
  if(!F){
    F=check(n,m,a,(c0-1)/2,n-1-(c1-1)/2);
  }
  if(!F){
    F=check(n,m,a,(c0-1)/2,(c1-1)/2);
  }
  if(!F){
    puts("-1");
  }
  return 0;
}