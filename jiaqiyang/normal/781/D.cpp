#include <cstdio>
#include <bitset>

typedef long long i64;

const int N = 500 + 10, S = 60;
const i64 INF = 1000000000000000000LL;

int n;

void mul(const std::bitset<N> a[], const std::bitset<N> b[], std::bitset<N> res[]) {
  static std::bitset<N> c[N];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      c[j][i] = b[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      res[i][j] = (a[i] & c[j]).any();
}

std::bitset<N> mask[2][S][N];

void init() {
  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x, --y;
    mask[z][0][x][y] = 1;
  }
  for (int i = 1; i < S; ++i)
    for (int j = 0; j < 2; ++j)
      mul(mask[j][i - 1], mask[!j][i - 1], mask[j][i]);
}

int main() {
  init();
  i64 ans = 0;
  static std::bitset<N> cur;
  cur.reset();
  cur[0] = 1;
  int s = 0;
  for (int i = S - 1; i >= 0; --i) {
    static std::bitset<N> temp;
    temp.reset();
    for (int j = 0; j < n; ++j) if (cur[j]) temp |= mask[s][i][j];
    if (temp.any()) {
      ans |= 1LL << i;
      s ^= 1;
      cur = temp;
    }
  }
  printf("%lld\n", ans > INF ? -1 : ans);
  return 0;
}