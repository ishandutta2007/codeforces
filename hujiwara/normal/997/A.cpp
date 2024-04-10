#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long x,y;
  scanf("%d%lld%lld",&n,&x,&y);
  static char s[300010];
  scanf("%s",s);
  int k=0;
  for(int i=0;i<n;i++){
    if((i==0||s[i-1]=='1')&&s[i]=='0'){
      k++;
    }
  }
  printf("%lld\n",k==0?0:y+min(x,y)*(k-1));
  return 0;
}