#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  static int a[100000],b[100000],c[200000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    c[i]=a[i];
  }
  for(int i=0;i<m;i++){
    scanf("%d",b+i);
    c[n+i]=b[i];
  }
  sort(c,c+n+m);
  for(int i=0;i<n;i++){
    a[i]=lower_bound(c,c+n+m,a[i])-c;
  }
  for(int i=0;i<m;i++){
    b[i]=lower_bound(c,c+n+m,b[i])-c;
  }
  int A[200000]={0},B[200000]={0};
  for(int i=0;i<n;i++){
    A[a[i]]++;
  }
  for(int i=0;i<m;i++){
    B[b[i]]++;
  }
  int AA=0,BB=0;
  bool F=0;
  for(int i=n+m-1;i>=0;i--){
    AA+=A[i];
    BB+=B[i];
    if(AA>BB){
      F=1;
      break;
    }
  }
  puts(F?"YES":"NO");
  return 0;
}