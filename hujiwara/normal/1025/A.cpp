#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static char s[100010];
  scanf("%s",s);
  int c[26]={0};
  for(int i=0;i<n;i++){
    c[s[i]-'a']++;
  }
  bool F=0;
  for(int i=0;i<26;i++){
    if(c[i]>=2){
      F=1;
    }
  }
  if(n==1)
    F=1;
  puts(F?"Yes":"No");
  return 0;
}