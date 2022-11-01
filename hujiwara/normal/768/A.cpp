#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int a[100000];
  int mn=1000000001,mx=-1;
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    mn=min(mn,a[i]);
    mx=max(mx,a[i]);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(mn<a[i]&&a[i]<mx){
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}