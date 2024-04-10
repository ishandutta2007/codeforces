#include <cstdio>
#include <cstring>
#include <algorithm>

#define fst first
#define snd second

typedef unsigned long long u64;

const int N = 100000 + 10, BASE = 27;
const u64 MOD1 = 1400305337, MOD2 = 1611623773; 

int n;
char s[N];

int succ[N];

std::pair<u64, u64> table[N], pow[N];

inline std::pair<u64, u64> hash(int l, int r) {
  std::pair<u64, u64> res;
  res.fst = (table[r].fst - table[l - 1].fst * pow[r - l + 1].fst % MOD1 + MOD1) % MOD1;
  res.snd = (table[r].snd - table[l - 1].snd * pow[r - l + 1].snd % MOD2 + MOD2) % MOD2;
  return res;
}

inline int lcp(int a, int b) {
  int l = 0, r = n - b + 1;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (hash(a, a + mid - 1) == hash(b, b + mid - 1)) l = mid; else r = mid - 1;
  }
  return l;
}

inline int lcs(int a, int b) {
  int l = 0, r = a;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (hash(a - mid + 1, a) == hash(b - mid + 1, b)) l = mid; else r = mid - 1;
  }
  return l;
}

bool Solve(int l) {
  bool res = false;
  for (int i = 1; i <= n; i += l) {
    int j = i + l;
    int a = lcp(i, j), b = lcs(i, j);
    if (a + b - 1 >= l) {
      res = true;
      break;
    }
  }
  if (res) {
    static int mark[N];
    for (int i = 1; i <= n;) {
      if (hash(i, i + l - 1) == hash(i + l, i + 2 * l - 1)) {
        for (int j = i; j < i + l; ++j) mark[j] = l;
        i += l;
      } else {
        ++i;
      }
    }
    int temp = 0;
    for (int i = 1; i <= n; ++i) if (mark[i] != l) s[++temp] = s[i];
    s[(n = temp) + 1] = '\0';
  }
  return res;
}

int main() {
  scanf(" %s", s + 1);
  n = strlen(s + 1);
  pow[0].fst = pow[0].snd = 1;
  for (int i = 1; i <= n; ++i) {
    pow[i].fst = pow[i - 1].fst * BASE % MOD1;
    pow[i].snd = pow[i - 1].snd * BASE % MOD2;
  }
  bool flag = true;
  for (int l = 1; 2 * l <= n; ++l) {
    if (flag) {
      table[0].fst = table[0].snd = 0;
      for (int i = 1; i <= n; ++i) {
        table[i].fst = (table[i - 1].fst * BASE + s[i] - 'a' + 1) % MOD1;
        table[i].snd = (table[i - 1].snd * BASE + s[i] - 'a' + 1) % MOD2;
      }
      flag = false;
    }
    flag |= Solve(l);
  }
  puts(s + 1);
  return 0;
}