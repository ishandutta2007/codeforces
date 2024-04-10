#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,M,Q;
  scanf("%d%d%d",&n,&M,&Q);
  int w[20];
  for(int i=0;i<n;i++){
    scanf("%d",w+i);
  }
  static int Ct[1<<12]={0};
  for(int t=0;t<M;t++){
    char s[20];
    scanf("%s",s);
    int I=0;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){
	I|=1<<i;
      }
    }
    Ct[I]++;
  }
  static int A[1<<12][110]={0};
  for(int I=0;I<(1<<n);I++){
    for(int J=0;J<(1<<n);J++){
      int S=0;
      for(int i=0;i<n;i++){
	if(((I>>i)&1)==((J>>i)&1)){
	  S+=w[i];
	}
      }
      if(S<=100){
	A[J][S]+=Ct[I];
      }
    }
  }
  for(int J=0;J<(1<<n);J++){
    for(int k=1;k<=100;k++){
      A[J][k]+=A[J][k-1];
    }
  }
  for(int t=0;t<Q;t++){
    char s[20];
    int k;
    scanf("%s%d",s,&k);
    int J=0;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){
	J|=1<<i;
      }
    }
    printf("%d\n",A[J][k]);
  }
  return 0;
}