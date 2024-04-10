#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  return b?gcd(b,a%b):a;
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[100];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  long long g=1;
  bool b[100]={0};
  for(int i=0;i<n;i++){
    if(b[i]){
      continue;
    }
    b[i]=1;
    int j=a[i],k=1;
    while(!b[j]&&j!=i){
      b[j]=1;
      j=a[j];
      k++;
    }
    if(i!=j){
      g=-1;
      break;
    }
    g=g*k/gcd(g,k);
  }
  if(g%2==0){
    g/=2;
  }
  printf("%I64d\n",g);
  return 0;
}