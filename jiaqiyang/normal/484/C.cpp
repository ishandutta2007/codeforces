#include <stdio.h>
#include <cctype>
#include <cstring>
#include <vector>

const int N = 1000000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n;
char s[N];

void comb(int l[], const int r[], int t) {
  static int temp[N];
  for (int i = 0; i < t; ++i) temp[i] = i;
  for (int i = 0; i + t < n; ++i) temp[i + t] = r[i] + t;
  static int res[N];
  for (int i = 0; i < n; ++i) res[i] = temp[l[i]];
  for (int i = 0; i < n; ++i) l[i] = res[i];
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  for (int tcase = nextInt(); tcase--;) {
    int k = nextInt();
    int d = nextInt();
    static int trans[N], res[N];
    for (int i = 0; i < n; ++i) res[i] = i;
    for (int i = 0; i < n; ++i) trans[i] = i;
    static std::vector<int> pool[N];
    for (int i = 0; i < d; ++i) pool[i].clear();
    for (int i = 0; i < k; ++i) pool[i % d].push_back(i);
    for (int i = 0, t = 0; i < d; ++i)
      for (int j = 0; j < pool[i].size(); ++j)
        trans[pool[i][j]] = t++;
    int exp = n - k + 1;
    for (int i = 1, cur = 0; i <= exp; i <<= 1) {
      if (exp & i) {
        comb(res, trans, cur);
        cur |= i;
      }
      comb(trans, trans, i);
    }
    static char t[N];
    for (int i = 0; i < n; ++i) t[res[i]] = s[i];
    for (int i = 0; i < n; ++i) s[i] = t[i];
    puts(s);
  }
  return 0;
}