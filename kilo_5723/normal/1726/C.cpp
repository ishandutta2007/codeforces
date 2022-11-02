#include <cstdio>
#include <iostream>

using namespace std;
const int maxn=2e5+5;
char s[maxn];
int dfs(char *&s){
  int res=(*s=='(');
  while (*s=='('){
    s++;
    res+=dfs(s);
    s++;
  }
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s",s);
    char *p=s;
    printf("%d\n",dfs(p));
    // printf("%d\n",p-s);
  }
  return 0;
}