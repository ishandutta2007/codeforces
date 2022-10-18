#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

struct UnionFind {
  vector<int> p;

  UnionFind(int n) : p(vector<int>(n)) {
    for (int i = 0; i < n; ++i) p[i] = i;
  }

  int findset(int x) { return x == p[x] ? x : p[x] = findset(p[x]); }

  void merge(int x, int y) { p[findset(x)] = findset(y); }
};

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  UnionFind uf(m + 1);

  vector<int> ret;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    vector<int> v(k);
    for (int j = 0; j < k; ++j) {
      cin >> v[j];
      --v[j];
    }
    if (v.size() == 1) v.push_back(m);

    int x = uf.findset(v[0]);
    int y = uf.findset(v[1]);
    if (x != y) {
      ret.push_back(i);
      uf.merge(x, y);
    }
  }

  int cnt = 1;
  for (int i = 0; i < (int)ret.size(); ++i) {
    cnt = (cnt * 2) % int(1e9 + 7);
  }

  cout << cnt << ' ' << ret.size() << '\n';
  for (int i : ret) cout << i + 1 << ' ';
  cout << '\n';

  return 0;
}