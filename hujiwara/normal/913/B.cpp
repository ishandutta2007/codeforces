#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int p[2000];
  for(int i=1;i<n;i++){
    scanf("%d",p+i);
    p[i]--;
  }
  int c[2000]={0};
  for(int i=1;i<n;i++){
    c[p[i]]++;
  }
  int d[2000]={0};
  for(int i=1;i<n;i++){
    if(c[i]==0){
      d[p[i]]++;
    }
  }
  bool F=1;
  for(int i=0;i<n;i++){
    if(!(c[i]==0||d[i]>=3)){
      F=0;
      break;
    }
  }
  puts(F?"YES":"NO");
  return 0;
}