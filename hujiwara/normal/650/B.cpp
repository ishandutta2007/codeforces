#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long a,b,T;
  scanf("%d%lld%lld%lld",&n,&a,&b,&T);
  static char s[500010];
  scanf("%s",s);
  static long long P[500010];
  P[0]=0;
  for(int i=0;i<n;i++){
    P[i+1]=P[i]+(s[i]=='h'?1:b+1);
  }
  int ans=0;
  for(int i=0,j=n;i<n;i++){
    long long r=T-(P[n]-P[n-i])-2*a*i;
    if(r<P[1]){
      break;
    }
    while(r<P[j]+a*(j-1)){
      j--;
    }
    //printf("%d %d\n",i,j);
    ans=max(ans,min(i+j,n));
  }
  for(int i=1,j=n;i<n;i++){
    long long r=T-P[i]-2*a*(i-1);
    if(r<0){
      break;
    }
    while(j>0&&r<P[n]-P[n-j]+a*j){
      j--;
    }
    //printf("%d %d\n",i,j);
    ans=max(ans,min(i+j,n));
  }
  printf("%d\n",ans);
  return 0;
}