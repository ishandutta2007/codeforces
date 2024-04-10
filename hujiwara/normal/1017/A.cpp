#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  int s=a+b+c+d;
  int ans=1;
  for(int i=1;i<n;i++){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int S=a+b+c+d;
    if(s<S){
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}