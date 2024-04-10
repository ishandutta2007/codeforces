#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

const i64 M = 1e10;

int main() {
  ios_base::sync_with_stdio(false);

  i64 a, b, c;
  cin >> a >> b >> c;
  vector<pair<i64, int>> v;
  v.push_back({a, 1});
  v.push_back({b, 2});
  v.push_back({c, 3});

  cout << "First\n";
  int idx = 0;
  while (true) {
    sort(v.begin(), v.end());
    i64 y = 0;
    if (idx == 0) {
      y = i64(M);
    } else if (idx == 1) {
      y = 2 * v[2].first - v[1].first - v[0].first;
    } else if (idx == 2) {
      y = v[2].first - v[1].first;
    } else {
      assert(false);
    }

    cout << y << '\n';
    cout.flush();

    int i;
    cin >> i;
    if (i <= 0) break;

    for (auto &p : v)
      if (p.second == i) p.first += y;
    idx++;
  }
  return 0;
}