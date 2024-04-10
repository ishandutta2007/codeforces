#include <cstdio>
#include <algorithm>
using namespace std;

int maxbit(int bit[1<<17],int i)
{
  i++;
  int k=0;
  while(i>0){
    k=max(k,bit[i]);
    i-=i&-i;
  }
  return k;
}

void bitadd(int bit[1<<17],int i,int k)
{
  i++;
  while(i<1<<17){
    bit[i]=max(bit[i],k);
    i+=i&-i;
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static int a[100000],A[100000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
    A[a[i]]=i;
  }
  static int b[100000],bit[1<<17]={0};
  for(int i=n-1;i>=0;i--){
    b[A[i]]=maxbit(bit,A[i])-1;
    bitadd(bit,A[i],A[i]+1);
    // printf("%d\n",A[i]);
  }
  int M=0;
  static int bit2[1<<17]={0};
  for(int i=0;i<n;i++){
    //printf("%d\n",b[i]);
    if(b[i]>=0){
      int j=b[i],k=maxbit(bit2,n-j-2);
      //printf("%d %d %d\n",i,j,k);
      bitadd(bit2,n-i-1,k+1);
      if(M<k+1){
	M=k+1;
      }
    }
  }
  printf("%d\n",M);
  return 0;
}