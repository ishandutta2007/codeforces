#include <bits/stdc++.h>

using namespace std;

const double EPS=1e-12;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  double p[20];
  for(int i=0;i<n;i++){
    scanf("%lf",p+i);
  }
  static double dp[1<<20]={0};
  dp[0]=1.;
  static double ans[20]={0};
  for(int I=0;I<1<<n;I++){
    int c=0;
    double s=0.;
    for(int i=0;i<n;i++){
      if((I>>i)&1){
	c++;
      }
      else{
	s+=p[i];
      }
    }
    if(c>k){
      continue;
    }
    if(c==k||s<EPS){
      for(int i=0;i<n;i++){
	if((I>>i)&1){
	  ans[i]+=dp[I];
	}
      }
      continue;
    }
    for(int i=0;i<n;i++){
      if(!((I>>i)&1)){
	dp[I|(1<<i)]+=dp[I]*p[i]/s;
      }
    }
  }
  for(int i=0;i<n;i++){
    printf("%.9lf%c",ans[i],i==n-1?'\n':' ');
  }
  return 0;
}