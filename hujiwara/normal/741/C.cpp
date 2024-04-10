#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int a[100000],b[100000],X[200010];
  for(int i=0;i<n;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--;
    b[i]--;
    X[a[i]]=b[i];
    X[b[i]]=a[i];
  }
  int B[200010]={0};
  for(int i=0;i<2*n;i+=2){
    if(B[i]!=0){
      continue;
    }
    B[i]=1;
    B[i+1]=2;
    int j=X[i+1];
    while(j!=i){
      B[j]=1;
      int k=(j%2==0?j+1:j-1);
      B[k]=2;
      j=X[k];
    }
  }
  for(int i=0;i<n;i++){
    printf("%d %d \n",B[a[i]],B[b[i]]);
  }
  return 0;
}