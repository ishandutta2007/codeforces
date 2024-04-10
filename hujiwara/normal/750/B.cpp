#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T=0;
  int n;
  scanf("%d",&n);
  bool F=0;
  for(int t=0;t<n;t++){
    int a;
    char s[10];
    scanf("%d%s",&a,s);
    if(s[0]=='S'){
      T+=a;
      if(T>20000){
	F=1;
	break;
      }
    }
    else if(s[0]=='N'){
      T-=a;
      if(T<0){
	F=1;
	break;
      }
    }
    else if(T==0||T==20000){
      F=1;
      break;
    }
  }
  puts(F||T!=0?"NO":"YES");
  return 0;
}