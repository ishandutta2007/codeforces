#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> pos[2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pos[(i+j)%2].push_back({i,j});
    }
  }
  auto put = [&](int k, int a) {
    assert(pos[k].size());
    auto [i,j] = pos[k].back();
    pos[k].pop_back();
    cout << a << ' ' << i+1 << ' ' << j+1 << endl;
  };
  for (int it = 0; it < n*n; it++) {
    int a;
    cin >> a;
    if (a != 1) {
      if (pos[0].empty()) put(1, (a != 2 ? 2 : 3));
      else put(0, 1);
    } else {
      assert(a != 2);
      if (pos[1].empty()) put(0, (a != 1 ? 1 : 3));
      else put(1, 2);
    }
  }
}