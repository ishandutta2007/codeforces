#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> point;

long long op(point P1,point P2)
{
  return imag((conj(P1)*P2));
}

long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}

long long cil(point P)
{
  long long d=gcd(abs(P.real()),abs(P.imag()));
  return d-1;
}

int N=40;

int main()
{
  int n;
  scanf("%d",&n);
  static point P[100000];
  for(int i=0;i<n;i++){
    long long x,y;
    scanf("%lld%lld",&x,&y);
    P[i]=point(x,y);
  }
  double p2[100];
  p2[0]=1.;
  for(int i=1;i<N+10;i++){
    p2[i]=p2[i-1]/2.;
  }
  double ans=0.;
  for(int i=0;i<n&&i<N;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n&&i+(k-j)<N;k++){
	ans+=p2[i+1+1+k-j]*(op(P[j]-P[i],P[k]-P[i])-1.)/2.;
	//printf("%d %d %d %lf %lf\n",i,j,k,ans,p2[i+1+1+k-j]*(op(P[j]-P[i],P[k]-P[i])-1.)/2.);
      }
    }
    for(int j=i+1;j<n&&j<N;j++){
      ans-=p2[j+1]*(1.-(n-j-1<N?p2[n-j-1]:0.))*cil(P[j]-P[i])/2.;
    }
    for(int j=n-1;j>i&&i+(n-j)<N;j--){
      ans-=p2[i+1+n-j]*(1.-(j-i-1<N?p2[j-i-1]:0.))*cil(P[i]-P[j])/2.;
    }
  }
  for(int j=0;j<n;j++){
    for(int k=j+1;k<n&&k-j<N;k++){
      ans-=p2[k-j+1]*(1.-(j<N?p2[j]:0.))*cil(P[k]-P[j])/2.;
    }
  }
  //printf("%.10lf\n",ans);
  ans/=1.-(n<N?(1.+n+(double)n*(n-1.)/2)*p2[n]:0.);
  printf("%.10lf\n",ans);
  return 0;
}