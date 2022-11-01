#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  scanf("%d",&n);
  int m[100000];
  long long N=0ll;
  for(int i=0;i<n;i++){
    scanf("%d",m+i);
    N+=m[i];
  }
  sort(m,m+n);
  long long T=0;
  for(int i=0;i<n;i++){
    int k=N/n;
    if(i>=n-N%n){
      k++;
    }
    if(k<=m[i]){
      T+=m[i]-k;
    }
  }
  printf("%I64d\n",T);
  return 0;
}