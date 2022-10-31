#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  scanf("%d",&n);
  static int a[2000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  int S[2010];
  S[0]=0;
  for(int i=0;i<n;i++){
    S[i+1]=S[i]+(a[i]==1);
  }
  int ans=max(S[n],n-S[n]);
  for(int j=0;j<n;j++){
    ans=max(ans,S[j]+(n-j-(S[n]-S[j])));
    if(a[j]==2)continue;
    int A=0,B=0;
    for(int i=j;i>=0;i--){
      if(a[i]==2){
	ans=max(ans,S[i]+B+1+(n-j-1-(S[n]-S[j+1])));
	B++;
      }
      else{
	A++;
	B=max(B,A);
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}