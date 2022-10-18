#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

const int MAX = 1000100;

int f[MAX];
int c[MAX];

int main() {
  c[1] = 1;
  for (int i = 2; i * i < MAX; ++i)
    if (!c[i])
      for (int j = i * i; j < MAX; j += i) c[j] = i;

  for (int i = 1; i < MAX; ++i) {
    int x = i;
    if (c[i] <= 1) {
      f[i] = x;
      continue;
    }

    int q = 0;
    while (x % c[i] == 0) x /= c[i], q++;

    x = f[x];
    if (q % 2) x *= c[i];
    f[i] = x;
  }

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<int, int> M;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      M[f[x]]++;
    }

    int t0 = 0;
    int c1 = 0;
    for (auto& p : M) {
      t0 = max(t0, p.second);
      if (p.first == 1 || p.second % 2 == 0) {
        c1 += p.second;
      }
    }

    int t1 = max(t0, c1);
    int q;
    cin >> q;
    while (q--) {
      i64 w;
      cin >> w;
      cout << (w == 0 ? t0 : t1) << '\n';
    }
  }

  return 0;
}