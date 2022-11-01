#include <bits/stdc++.h>
using namespace std;

const int INF=10000;

int main()
{
  int n;
  scanf("%d",&n);
  int C[500];
  for(int i=0;i<n;i++){
    scanf("%d",C+i);
  }
  static int c[501][501];
  for(int i=0;i<=n;i++){
    c[i][i]=1;
  }
  for(int i=0;i+1<=n;i++){
    c[i][i+1]=1;
  }
  for(int w=2;w<=n;w++){
    for(int i=0;i+w<=n;i++){
      int j=i+w;
      c[i][j]=INF;
      for(int k=i+1;k<j;k++){
	c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
      }
      if(C[i]==C[j-1]){
	c[i][j]=min(c[i][j],c[i+1][j-1]);
      }
    }
  }
  printf("%d\n",c[0][n]);
  return 0;
}