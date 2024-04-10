#include <cstdio>

int main()
{
  int n;
  static char s[2000001],t[2000001];
  scanf("%d%s%s",&n,s,t);
  int a=0,b=0,c=0;
  for(int i=0;i<2*n;i++){
    if(s[i]=='1'&&t[i]=='1'){
      a++;
    }
    else if(s[i]=='1'&&t[i]=='0'){
      b++;
    }
    else if(s[i]=='0'&&t[i]=='1'){
      c++;
    }
  }
  int F=0,S=0;
  for(int t=0;t<n;t++){
    if(a){
      a--;
      F++;
    }
    else if(b){
      b--;
      F++;
    }
    else if(c){
      c--;
    }
    if(a){
      a--;
      S++;
    }
    else if(c){
      c--;
      S++;
    }
    else if(b){
      b--;
    }
  }
  if(F>S){
    puts("First");
  }
  else if(F<S){
    puts("Second");
  }
  else{
    puts("Draw");
  }
  return 0;
}