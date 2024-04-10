#include <bits/stdc++.h>
using namespace std;
const int INF=1100000000;
int main()
{
  int n;
  scanf("%d",&n);
  static int B[1000][10][2];
  for(int t=0;t<10;t++){
    int k=0;
    for(int i=0;i<n;i++){
      if(!((i>>t)&1)){
	k++;
      }
    }
    if(k>0){
      printf("%d\n",k);
      for(int i=0;i<n;i++){
	if(!((i>>t)&1)){
	  printf("%d ",i+1);
	}
      }
      putchar('\n');
      fflush(stdout);
      for(int i=0;i<n;i++){
	scanf("%d",B[i][t]+0);
      }
    }
    else{
      for(int i=0;i<n;i++){
	B[i][t][0]=INF;
      }
    }
    if(n-k>0){
      printf("%d\n",n-k);
      for(int i=0;i<n;i++){
	if((i>>t)&1){
	  printf("%d ",i+1);
	}
      }
      putchar('\n');
      fflush(stdout);
      for(int i=0;i<n;i++){
	scanf("%d",B[i][t]+1);
      }
    }
    else{
      for(int i=0;i<n;i++){
	B[i][t][1]=INF;
      }
    }
  }
  printf("-1\n");
  for(int i=0;i<n;i++){
    int M=INF;
    for(int t=0;t<10;t++){
      M=min(M,B[i][t][!((i>>t)&1)]);
    }
    printf("%d ",M);
  }
  putchar('\n');
  return 0;
}