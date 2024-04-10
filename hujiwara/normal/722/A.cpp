#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  char s[10];
  scanf("%s",s);
  if(n==12){
    if((s[0]-'0')*10+(s[1]-'0')>12){
      s[0]=(s[1]<='2'?'1':'0');
    }
    else if(s[0]=='0'&&s[1]=='0'){
      s[1]='1';
    }
  }
  else{
    if((s[0]-'0')*10+(s[1]-'0')>=24){
      s[0]='0';
    }
  }
  if((s[3]-'0')>=6){
    s[3]='0';
  }
  printf("%s\n",s);
  return 0;
}