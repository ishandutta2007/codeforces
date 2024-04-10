#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&(a[i]));
  }
  sort(a.begin(),a.end());
  int ct=0,c=0;
  for(int i=0;i<n;i++){
    if(i>0&&a[i-1]==a[i]){
      c++;
    }
    else{
      c=1;
    }
    ct=max(ct,c);
  }
  printf("%d\n",n-ct);
  return 0;
}