#include <cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  int p[100];
  for(int i=0;i<n;i++){
    scanf("%d",p+i);
  }
  scanf("\n");
  bool F=1;
  for(int i=0;i<n;i++){
    char c;
    int C=0;
    while((c=getchar())!='\n'){
      if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'||c=='y'){
	C++;
      }
    }
    if(C!=p[i]){
      F=0;
    }
  }
  printf(F?"YES":"NO");
  return 0;
}