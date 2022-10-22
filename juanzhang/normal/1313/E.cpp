#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, ll> pii;
const int maxn = 5e5 + 10;
char A[maxn], B[maxn], str[maxn << 1];
int n, m, valA[maxn], valB[maxn];

void exkmp(char *A, char *B, int *ans) {
  static int ext[maxn * 3];
  static char str[maxn * 3];
  memset(ext, 0, sizeof ext);
  ext[1] = m;
  str[m + 1] = '#';
  rep(i, 1, m) str[i] = B[i];
  rep(i, 1, n) str[m + i + 1] = A[i];
  int len = n + m + 1, pos = 0, mx = 0;
  rep(i, 2, len) {
    if (i <= mx) ext[i] = min(ext[i - pos + 1], mx - i + 1);
    while (str[ext[i] + 1] == str[i + ext[i]]) ++ext[i];
    if (mx < i + ext[i] - 1) pos = i, mx = i + ext[i] - 1;
  }
  rep(i, 1, n) ans[i] = min(ext[m + i + 1], m - 1);
}

int c[maxn << 1]; ll sum[maxn << 1];

void add(int pos, int x) {
  int val = pos * x;
  for (; pos; pos &= pos - 1) {
    c[pos] += x, sum[pos] += val;
  }
}

pii query(int pos) {
  int cnt = 0; ll res = 0;
  for (; pos <= m; pos += pos & -pos) {
    cnt += c[pos], res += sum[pos];
  }
  return pii(cnt, res);
}

int main() {
  cin >> n >> m;
  scanf("%s %s %s", A + 1, B + 1, str + 1);
  exkmp(A, str, valA);
  reverse(B + 1, B + n + 1);
  reverse(str + 1, str + m + 1);
  exkmp(B, str, valB);
  reverse(valB + 1, valB + n + 1);
  ll res = 0;
  per(i, n, 1) {
    int r = min(n, i + m - 2);
    add(valB[i], 1);
    if (r < n) add(valB[r + 1], -1);
    pii p = query(m - valA[i]);
    res += p.second + 1ll * p.first * (valA[i] - m + 1);
  }
  cout << res;
  return 0;
}