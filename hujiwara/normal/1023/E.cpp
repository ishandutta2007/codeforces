#include <bits/stdc++.h>
using namespace std;

bool ask(int r1,int c1,int r2,int c2)
{
  printf("? %d %d %d %d\n",r1+1,c1+1,r2+1,c2+1);
  fflush(stdout);
  char s[5];
  scanf("%s",s);
  assert(s[0]!='B');
  return s[0]=='Y';
}


int main()
{
  int n;
  scanf("%d",&n);
  string str;
  int x=0,y=0;
  while(x+y<n-1){
    if(x+1<n&&ask(x+1,y,n-1,n-1)){
      str+='D';
      x++;
    }
    else{
      str+='R';
      y++;
    }
  }
  x=n-1,y=n-1;
  string str2;
  while(x+y>n-1){
    if(y>0&&ask(0,0,x,y-1)){
      str2+='R';
      y--;
    }
    else{
      str2+='D';
      x--;
    }
  }
  for(int t=str2.size()-1;t>=0;t--){
    str+=str2[t];
  }
  printf("! %s\n",str.c_str());
  fflush(stdout);
  return 0;
}