#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static pair<int,int> a[300000];
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i].first));
    a[i].second=i;
  }
  sort(a,a+n);
  static int b[300000];
  int k=-1;
  for(int i=0;i<n;i++){
    if(k>=a[i].first){
      k++;
      b[a[i].second]=k;
    }
    else{
      k=a[i].first;
      b[a[i].second]=k;
    }
  }
  for(int i=0;i<n;i++){
    printf("%d ",b[i]);
  }
  putchar('\n');
  return 0;
}