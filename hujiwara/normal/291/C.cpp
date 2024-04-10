#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  unsigned int M[100000];
  for(int i=0;i<n;i++){
    unsigned int a,b,c,d;
    scanf("%u.%u.%u.%u",&a,&b,&c,&d);
    M[i]=a<<24|b<<16|c<<8|d;
  }
  bool b=1;
  for(int i=1;i<32;i++){
    unsigned int m=0;
    for(int j=0;j<i;j++){
      m|=1u<<31-j;
    }
    unsigned int N[100000];
    for(int j=0;j<n;j++){
      N[j]=M[j]&m;
    }
    sort(N,N+n);
    int p=0;
    for(int j=0;j<n;j++){
      if(j==0||N[j-1]<N[j]){
	p++;
      }
    }
    //printf("%d\n",p);
    if(p==k){
      printf("%u.%u.%u.%u\n",m>>24,(m>>16)&255u,(m>>8)&255u,m&255u);
      b=0;
      break;
    }
    else if(p>k){
      break;
    }
  }
  if(b){
    printf("%d\n",-1);
  }
  return 0;
}