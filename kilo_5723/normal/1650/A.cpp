#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main() {
  int tt;
  scanf("%d",&tt);
  while (tt--){
    scanf("%s",s);
    getchar();
    char ch=getchar();
    bool flg=false;
    for (int i=0;s[i];i++) if (!(i&1)&&s[i]==ch) flg=true;
    puts(flg?"YES":"NO");
  }
  return 0;
}