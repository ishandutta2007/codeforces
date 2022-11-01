#include <bits/stdc++.h>
using namespace std;

int main()
{
  char s[501];
  int N=0;
  scanf("%s",s);
  int n=strlen(s);
  bool F=1;
  for(int i=0;i<n;i++){
    int c=s[i]-'a';
    if(c==N){
      N++;
    }
    else if(c>N){
      F=0;
      break;
    }
  }
  puts(F?"YES":"NO");
  return 0;
}