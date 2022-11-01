#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  long long a[500000];
  for(int i=0;i<n;i++){
    scanf("%I64d",a+i);
  }
  long long T=0ll;
  sort(a,a+n);
  for(int i=0;i<n;i++){
    if(i==n-1){
      T+=n*a[i];
    }
    else{
      T+=(i+2)*a[i];
    }
  }
  printf("%I64d\n",T);
  return 0;
}