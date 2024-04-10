#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static int L[1000000],R[1000000],X[2000000];
  for(int i=0;i<n;i++){
    scanf("%d%d",L+i,R+i);
    X[i]=L[i];
    X[n+i]=R[i];
  }
  sort(X,X+2*n);
  for(int i=0;i<n;i++){
    L[i]=lower_bound(X,X+2*n,L[i])-X;
    R[i]=lower_bound(X,X+2*n,R[i])-X;
  }
  static int D[4000000];
  for(int i=0;i<n;i++){
    D[2*L[i]]++;
    D[2*R[i]+1]--;
  }
  for(int i=0;i<4*n-1;i++){
    D[i+1]+=D[i];
  }
  int m=0;
  for(int i=0;i<4*n;i++){
    if((i==0||D[i-1]<k)&&D[i]>=k){
      m++;
    }
  }
  printf("%d\n",m);
  for(int i=0;i<4*n;i++){
    if((i==0||D[i-1]<k)&&D[i]>=k){
      printf("%d ",X[i/2]);
    }
    if((i>0&&D[i-1]>=k)&&D[i]<k){
      printf("%d\n",X[i/2]);
    }
  }
  return 0;
}