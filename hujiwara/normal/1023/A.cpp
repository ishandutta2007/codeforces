#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static char s[300000],t[300000];
  scanf("%s%s",s,t);
  int c=-1;
  for(int i=0;i<n;i++){
    if(s[i]=='*'){
      c=i;
    }
  }
  bool F;
  if(c!=-1){
    F=(n-1<=m?1:0);
    for(int i=0;s[i]!='*';i++){
      if(s[i]!=t[i]){
	F=0;
	break;
      }
    }
    for(int i=0;s[n-i-1]!='*';i++){
      if(s[n-i-1]!=t[m-i-1]){
	F=0;
	break;
      }
    }
  }
  else{
    F=!strcmp(s,t);
  }
  puts(F?"YES":"NO");
  return 0;
}