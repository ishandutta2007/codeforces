#include <cstdio>
#include <cstring>

int main()
{
  static char s[100010];
  scanf("%s",s);
  int n=strlen(s);
  bool b=0;
  if(n%2==0){
    int k=0;
    for(int i=0;i<n;i+=2){
      if(s[i]!=s[i+1]){
	if(s[i]=='+'){
	  k++;
	}
	else{
	  k--;
	}
      }
    }
    if(k==0){
      b=1;
    }
  }
  puts(b?"Yes":"No");
  return 0;
}