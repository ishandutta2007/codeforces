#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
      if (i & 1)
        s[i] = s[i] == 'z' ? 'y' : 'z';
      else
        s[i] = s[i] == 'a' ? 'b' : 'a';
    printf("%s\n", s);
  }
  return 0;
}