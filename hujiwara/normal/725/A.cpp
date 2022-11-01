#include <cstdio>
#include <cstring>

int main()
{
  int n;
  static char s[300000];
  scanf("%d%s",&n,s);
  int c=0;
  for(int i=0;i<n&&s[i]=='<';i++){
    c++;
  }
  for(int i=n-1;i>=0&&s[i]=='>';i--){
    c++;
  }
  printf("%d\n",c);
  return 0;
}