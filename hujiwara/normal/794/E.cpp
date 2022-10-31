#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static int a[300000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  static int b[300000]={0};
  for(int i=0;i+1<n;i++){
    int k=min(i,n-i-2);
    b[n-2*k-2]=max(b[n-2*k-2],max(a[i],a[i+1]));
  }
  for(int i=1;i+1<n;i++){
    int k=min(i,n-i-1);
    b[n-2*k-1]=max(b[n-2*k-1],max(min(a[i-1],a[i]),min(a[i],a[i+1])));
  }
  for(int i=0;i<n;i++){
    b[n-1]=max(b[n-1],a[i]);
  }
  for(int i=2;i<n;i++){
    b[i]=max(b[i],b[i-2]);
  }
  for(int i=0;i<n;i++){
    printf("%d%c",b[i],i==n-1?'\n':' ');
  }
  return 0;
}