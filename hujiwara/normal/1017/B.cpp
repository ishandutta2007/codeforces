#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static char a[100010],b[100010];
  scanf("%s%s",a,b);
  long long c[2][2]={0};
  for(int i=0;i<n;i++){
    c[a[i]-'0'][b[i]-'0']++;
  }
  printf("%lld\n",c[0][0]*c[1][0]+c[0][0]*c[1][1]+c[0][1]*c[1][0]);
  return 0;
}