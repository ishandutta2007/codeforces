#include <bits/stdc++.h>
using namespace std;
int main()
{
  char a[2000];
  scanf("%s",a);
  int n=strlen(a);
  printf("%s",a);
  for(int i=n-1;i>=0;i--){
    putchar(a[i]);
  }
  puts("");
  return 0;
}