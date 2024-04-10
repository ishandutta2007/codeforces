#include <bits/stdc++.h>
using namespace std;

int main()
{
  static char s1[300010],s2[300010],ans[300010];
  scanf("%s%s",s1,s2);
  int n=strlen(s1);
  sort(s1,s1+n);
  sort(s2,s2+n);
  int i;
  for(i=0;i<n&&s1[(i+1)/2]<s2[n-i/2-1];i++){
    ans[i]=(i%2==0?s1[i/2]:s2[n-i/2-1]);
  }
  for(int j=0;i+j<n;j++){
    ans[n-j-1]=((i+j)%2==0?s1[(n+1)/2-j/2-1]:s2[(n+1)/2+j/2]);
  }
  ans[n]=0;
  printf("%s\n",ans);
  return 0;
}