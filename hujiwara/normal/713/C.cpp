#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static long long a[3000],X[3000];
  for(int i=0;i<n;i++){
    scanf("%I64d",a+i);
    a[i]-=i;
    X[i]=a[i];
  }
  sort(X,X+n);
  static long long dp[2][3000];
  bool b=0;
  for(int j=0;j<n;j++){
    if(X[j]<=a[0]){
      dp[b][j]=a[0]-X[j];
    }
    else{
      dp[b][j]=0;
    }
  }
  for(int i=1;i<n;i++){
    dp[!b][0]=dp[b][0]+abs(X[0]-a[i]);
    for(int j=1;j<n;j++){
      dp[!b][j]=min(dp[!b][j-1],dp[b][j]+abs(X[j]-a[i]));
    }
    b=!b;
  }
  printf("%I64d\n",dp[b][n-1]);
  return 0;
}