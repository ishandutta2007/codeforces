#include <cstdio>
#include <stack>
using namespace std;

int main()
{
  int n=0;
  stack<char> S;
  char c;
  while((c=getchar())!='\n'){
    if(c==')'||c==']'||c=='}'||c=='>'){
      if(S.empty()){
	n=-1;
	break;
      }
      char d=S.top();
      S.pop();
      if(!((d=='('&&c==')')||(d=='['&&c==']')||(d=='{'&&c=='}')||(d=='<'&&c=='>'))){
	n++;
      }
    }
    else{
      S.push(c);
    }
  }
  if(n>=0&&S.empty()){
    printf("%d\n",n);
  }
  else{
    puts("Impossible");
  }
  return 0;
}