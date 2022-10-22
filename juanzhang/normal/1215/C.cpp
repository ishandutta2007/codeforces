#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

typedef pair <int, int> pii;
const int maxn = 2e5 + 10;
int n;
char S[maxn], T[maxn];

vector <pii> ans;
vector <int> v1, v2;

int main() {
  scanf("%d %s %s", &n, S + 1, T + 1);
  for (int i = 1; i <= n; i++) {
    if (S[i] != T[i]) {
      if (S[i] == 'a') v1.push_back(i);
      if (S[i] == 'b') v2.push_back(i);
    }
  }
  int s1 = v1.size(), s2 = v2.size();
  if ((s1 & 1) != (s2 & 1)) {
    return puts("-1"), 0;
  }
  if (!s1 && !s2) {
    return puts("0"), 0;
  }
  if (s1 < s2) {
    swap(s1, s2), swap(v1, v2);
  }
  while (s1 > 1) {
    int x = v1.back();
    v1.pop_back();
    int y = v1.back();
    v1.pop_back();
    ans.push_back(pii(x, y));
    s1 -= 2;
  }
  while (s2 > 1) {
    int x = v2.back();
    v2.pop_back();
    int y = v2.back();
    v2.pop_back();
    ans.push_back(pii(x, y));
    s2 -= 2;
  }
  if (s1 && s2) {
    int x = v1.back(), y = v2.back();
    ans.push_back(pii(y, y));
    ans.push_back(pii(y, x));
    v1.pop_back();
    v2.pop_back();
  }
  printf("%d\n", (int) ans.size());
  for (pii p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}