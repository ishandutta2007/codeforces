#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  int n;
  int m[300000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",m+i);
  }
  static long long A[100][100][101]={0};
  for(int i=1;i<100;i++){
    for(int k=0;k<n;k++){
      A[i][k%i][k/3000]+=m[k];
    }
    for(int j=0;j<i;j++){
      for(int k=99;k>=0;k--){
	A[i][j][k]+=A[i][j][k+1];
      }
    }
  }
  int p;
  scanf("%d",&p);
  while(p--){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    if(b<100){
      long long L=0;
      int k=a/3000;
      for(int i=a;i<3000*(k+1);i+=b){
	L+=m[i];
      }
      L+=A[b][a%b][k+1];
      cout<<L<<'\n';
    }
    else{
      long long L=0;
      for(int i=a;i<n;i+=b){
	L+=m[i];
      }
      cout<<L<<'\n';
    }
  }
  return 0;
}