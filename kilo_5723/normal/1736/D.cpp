#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0;
    for (int i = 0; i < n << 1; i++) cnt += s[i] - '0';
    if (cnt & 1) {
      puts("-1");
      continue;
    }
    char ch = '0';
    vector<int> ans;
    for (int i = 0; i < n << 1; i += 2) {
      if (s[i] == s[i + 1]) continue;
      ans.push_back(s[i] == ch ? i + 1 : i + 2);
      ch ^= 1;
    }
    printf("%u", ans.size());
    for (auto v : ans) printf(" %d", v);
    puts("");
    for (int i = 1; i < n << 1; i += 2) printf("%d ", i);
    puts("");
  }
  return 0;
}