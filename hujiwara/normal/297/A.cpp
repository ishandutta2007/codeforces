#include <cstdio>

int main()
{
  char a[2000],b[2000];
  scanf("%s%s",a,b);
  int A=0,B=0;
  for(int i=0;a[i];i++){
    if(a[i]=='1'){
      A++;
    }
  }
  for(int i=0;b[i];i++){
    if(b[i]=='1'){
      B++;
    }
  }
  if(A>=B||(A%2==1&&A+1==B)){
    puts("YES");
  }
  else{
    puts("NO");
  }
  return 0;
}