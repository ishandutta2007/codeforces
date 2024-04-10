#include <cstdio>
#include <algorithm>

#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int
#define FIO ""
#define dbug(...) fprintf(stderr, __VA_ARGS__)

template <typename Y> inline bool updmin(Y &a, Y b){if (a > b) {a = b; return 1;} return 0;}
template <typename Y> inline bool updmax(Y &a, Y b){if (a < b) {a = b; return 1;} return 0;}
template <typename Y> inline Y abs(Y a){if (a < 0) a = -a; return a;}
template <typename Y> inline Y sqr(Y a){return a * a;}

typedef std::pair<int, int> par;
#define fx first
#define fy second
#define mpar std::make_pair
#define pb push_back

int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

const int N = 2050;
#include <vector>
int n, m;
std::vector<int> G[N];
#include <bitset>
std::bitset<N> a[N];
int b[N];

void Main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    G[i].clear();
    a[i].reset();
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    G[x].pb(y);
    G[y].pb(x);
  }
  int tg = 1;
  for (int i = 1; i <= n; i++) {
    if (G[i].size() & 1) {
      tg = 0;
      break;
    }
  }
  if (tg) {
    puts("1");
    for (int i = 1; i <= n; i++) {
      printf("1 ");
    }
    puts("");
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (G[i].size() & 1) {
      a[i].set(i);
      a[i].set(n + 1);
    }
    for (auto x : G[i]) {
      a[i].set(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (a[j].test(i)) {
        std::swap(a[i], a[j]);
        break;
      }
    }
    if (!a[i].test(i)) continue;
    for (int j = i + 1; j <= n; j++) {
      if (a[j].test(i)) {
        a[j] ^= a[i];
      }
    }
  }
  for (int i = n; i; i--) {
    if (!a[i].test(i)) {
      b[i] = 0;
      continue;
    }
    int ans = a[i].test(n + 1);
    for (int j = i + 1; j <= n; j++) {
      if (a[i].test(j)) {
        ans ^= b[j];
      }
    }
    b[i] = ans;
  }
  puts("2");
  for (int i = 1; i <= n; i++) {
    printf("%d ", b[i] + 1);
  }
  puts("");
}

int main() {
  int T = read();
  while (T--) {
    Main();
  }
  return 0;
}