#include <bits/stdc++.h>
using namespace std;

const int N=2000;

void inv_mat(int n,bool M[N][N],bool X[N][N])
{
  long long A[N][N/60+1]={0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      A[i][j/60]|=(long long)M[i][j]<<(j%60);
    }
  }
  long long B[N][N/60+1]={0};
  for(int i=0;i<n;i++){
    B[i][i/60]|=1ll<<(i%60);
  }
  for(int i=0;i<n;i++){
    int l=i;
    while(!((A[l][i/60]>>(i%60))&1)){
      l++;
    }
    for(int j=0;j<n/60+1;j++){
      swap(A[i][j],A[l][j]);
      swap(B[i][j],B[l][j]);
    }
    for(int k=0;k<n;k++){
      if(k==i||!((A[k][i/60]>>(i%60))&1)){
	continue;
      }
      for(int j=0;j<n/60+1;j++){
	A[k][j]^=A[i][j];
	B[k][j]^=B[i][j];
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      X[i][j]=((B[i][j/60]>>(j%60))&1);
    }
  }
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int a[500000],b[500000];
  static bool A[2000][2000]={0};
  for(int i=0;i<m;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--,b[i]--;
    A[a[i]][b[i]]=1;
  }
  static bool X[2000][2000];
  inv_mat(n,A,X);
  /*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ",A[i][j]);
    }
    putchar('\n');
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ",X[i][j]);
    }
    putchar('\n');
    }*/
  for(int i=0;i<m;i++){
    puts(!X[b[i]][a[i]]?"YES":"NO");
  }
  return 0;
}