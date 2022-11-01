#include <cstdio>

int main()
{
  int n,t;
  scanf("%d%d",&n,&t);
  static char s[300000];
  scanf("%s",s);
  int a=0;
  while(s[a]!='.'){
    a++;
  }
  a++;
  while(a<n&&s[a]-'0'<=4){
    a++;
  }
  if(a<n){
    a--;
    t--;
    while(a>=0){
      if(s[a]=='.'){
	a--;
	int b=a;
	while(b>=0){
	  if(s[b]=='9'){
	    s[b]='0';
	    b--;
	  }
	  else{
	    s[b]++;
	    break;
	  }
	}
	if(b==-1){
	  putchar('1');
	}
	break;
      }
      else if(s[a]=='9'){
	a--;
      }
      else if(s[a]=='4'){
	if(t>0){
	  t--;
	  a--;
	}
	else{
	  s[a]='5';
	  break;
	}
      }
      else{
	s[a]++;
	break;
      }
    }
    s[a+1]=0;
  }
  printf("%s\n",s);
  return 0;
}