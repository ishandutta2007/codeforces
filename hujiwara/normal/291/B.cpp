#include <cstdio>

int main()
{
  char c;
  bool b=0;
  char s[100002];
  int k=0;
  while((c=getchar())!=EOF){
    if(b){
      if(c=='\"'){
	s[k]=0;
	printf("<%s>\n",s);
	k=0;
	b=0;
      }
      else{
	s[k]=c;
	k++;
      }
    }
    else{
      if(c==' '||c=='\n'){
	if(k>0){
	  s[k]=0;
	  printf("<%s>\n",s);
	  k=0;
	}
      }
      else if(c=='\"'){
	b=1;
      }
      else{
	s[k]=c;
	k++;
      }
    }
  }
  putchar('\n');
  return 0;
}