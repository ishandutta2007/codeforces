#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n,l,r,q,Q;
  scanf("%d%d%d%d%d",&n,&r,&l,&Q,&q);
  static int w[100000];
  for(int i=0;i<n;i++){
    scanf("%d",w+i);
  }
  static int W[100001];
  W[0]=0;
  for(int i=0;i<n;i++){
    W[i+1]=W[i]+w[i];
  }
  int M=W[n]*l+n*q,P=0;
  for(int t=0,i=0,j=n-1;t<n;){
    P+=w[j]*l;
    j--;
    t++;
    //printf("%d %d %d\n",M,P,i,j);
    if(M>P+(W[j+1]-W[i])*l+(j-i+1)*q){
      M=P+(W[j+1]-W[i])*l+(j-i+1)*q;
    }
    if(t<n){
      P+=w[i]*r;
      i++;
      t++;
      if(M>P+(W[j+1]-W[i])*r+(j-i+1)*Q){
	M=P+(W[j+1]-W[i])*r+(j-i+1)*Q;
      }
    }
  }
  P=0;
  for(int t=0,i=0,j=n-1;t<n;){
    P+=w[i]*r;
    i++;
    t++;
    if(M>P+(W[j+1]-W[i])*r+(j-i+1)*Q){
      M=P+(W[j+1]-W[i])*r+(j-i+1)*Q;
    }
    if(t<n){
      P+=w[j]*l;
      j--;
      t++;
      if(M>P+(W[j+1]-W[i])*l+(j-i+1)*q){
	M=P+(W[j+1]-W[i])*l+(j-i+1)*q;
      }
    }
  }
  printf("%d\n",M);
  return 0;
}