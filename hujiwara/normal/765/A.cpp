#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  scanf("%d",&n);
  char s[10];
  scanf("%s",s);
  int a=0,b=0;
  for(int i=0;i<n;i++){
    char t[10];
    scanf("%s",t);
    if(s[0]==t[0]&&s[1]==t[1]&&s[2]==t[2]){
      a++;
    }
    if(s[0]==t[5]&&s[1]==t[6]&&s[2]==t[7]){
      b++;
    }
  }
  puts(a>b?"contest":"home");
  return 0;
}