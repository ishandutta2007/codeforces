#include <cstdio>

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int P[10000];
  for(int i=0;i<n-1;i++){
    P[i]=1;
  }
  P[n-1]=0;
  for(int t=0;t<k;t++){
    for(int i=0;i<n;i++){
      int A;
      if(P[i]==n-i-1){
	A=0;
      }
      else if(2*P[i]<=n-i-1){
	A=P[i];
      }
      else{
	A=n-i-1-P[i];
      }
      P[i]+=A;
      printf("%d%c",n-A,i<n-1?' ':'\n');
    }
  }
  return 0;
}