#include <bits/stdc++.h>

typedef long long int64;

const int N = 200000 + 10, MOD = 1000000007;

inline void MUL(int &a, int b) { a = (int64)a * b % MOD; }

int n, m, tot;
int anc[N], zero[N], one[N];

inline int find(int a) { return anc[a] == a ? a : (anc[a] = find(anc[a])); }
inline int join(int a, int b) { anc[find(b)] = find(a); }


inline void add(int x, int y, int val) {
  if (x > y) std::swap(x, y);
  int st = y - x + 1;
  int ed = st + (std::min(n - y + 1, x) - 1) * 2;
  st = std::max(st - 2, 0);
  if (val) {
    join(zero[st], one[ed]);
    join(one[st], zero[ed]);
  } else {
    join(zero[st], zero[ed]);
    join(one[st], one[ed]);
  }
}

inline int pow(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) MUL(res, base);
    MUL(base, base);
  }
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d", &n, &m);
  tot = 0;
  for (int i = 0; i <= n; ++i) {
    zero[i] = ++tot;
    one[i] = ++tot;
  }
  for (int i = 1; i <= tot; ++i) anc[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    char ch;
    scanf("%d%d %c", &x, &y, &ch);
    add(x, y, ch == 'o');
  }
  for (int i = 0; i <= n; ++i) {
    if (find(zero[i]) == find(one[i])) {
      puts("0");
      exit(0);
    }
  }
  int ans = 0;
  for (int i = 1; i <= tot; ++i) ans += (find(i) == i);
  printf("%d\n", pow(2, (ans - 2) / 2));
  return 0;
}