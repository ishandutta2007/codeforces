#include <cstdio>

int main()
{
  int n,p,q;
  scanf("%d%d%d",&n,&p,&q);
  bool F=0;
  char s[100];
  scanf("%s",s);
  for(int l=0;l*p<=n;l++){
    if((n-l*p)%q==0){
      F=1;
      printf("%d\n",l+(n-l*p)/q);
      for(int k=0;k<l;k++){
	for(int i=0;i<p;i++){
	  putchar(s[k*p+i]);
	}
	putchar('\n');
      }
      for(int k=0;k<(n-l*p)/q;k++){
	for(int i=0;i<q;i++){
	  putchar(s[l*p+k*q+i]);
	}
	putchar('\n');
      }
      break;
    }
  }
  if(F==0){
    puts("-1");
  }
  return 0;
}