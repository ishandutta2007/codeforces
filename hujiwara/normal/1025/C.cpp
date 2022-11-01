#include <bits/stdc++.h>
using namespace std;

int main()
{
  char s[200010];
  scanf("%s",s);
  int n=strlen(s);
  for(int i=0;i<n;i++){
    s[i+n]=s[i];
  }
  int ans=1,c=1;
  for(int i=1;i<2*n;i++){
    if(s[i-1]!=s[i]){
      c++;
      ans=max(ans,c);
    }
    else{
      c=1;
    }
  }
  printf("%d\n",min(ans,n));
  return 0;
}