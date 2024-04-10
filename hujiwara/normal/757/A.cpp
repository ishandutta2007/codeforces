#include <bits/stdc++.h>
using namespace std;

int main()
{
  static char s[100010];
  scanf("%s",s);
  int A[26]={0},B[26]={0};
  for(int i=0;s[i];i++){
    if('a'<=s[i]&&s[i]<='z'){
      A[s[i]-'a']++;
    }
    else{
      B[s[i]-'A']++;
    }
  }
  int m=B['B'-'A'];
  m=min(m,A['u'-'a']/2);
  m=min(m,A['l'-'a']);
  m=min(m,A['b'-'a']);
  m=min(m,A['a'-'a']/2);
  m=min(m,A['s'-'a']);
  m=min(m,A['r'-'a']);
  printf("%d\n",m);
  return 0;
}