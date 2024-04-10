#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

const int MaxN = 200000;
const int MaxNV = MaxN * 2;

int n, m, q;
int ufs[MaxNV + 1];

int ufs_find(const int &u) {
  return ufs[u] == u ? u : ufs[u] = ufs_find(ufs[u]);
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n + m; ++i) {
    ufs[i] = i;
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    int u = ufs_find(x + 0);
    int v = ufs_find(y + n);
    ufs[u] = v;
  }

  int res = -1;
  for (int i = 1; i <= n + m; ++i) {
    res += ufs[i] == i;
  }

  cout << res << endl;

  return 0;
}