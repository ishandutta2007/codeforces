#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<set<int>> node(n);
  int ans = n;
  auto good = [&](int p) {
    return node[p].empty() || *node[p].rbegin() < p;
  };
  auto add = [&](int a, int b) {
    ans -= good(a)+good(b);
    node[a].insert(b);
    node[b].insert(a);
    ans += good(a)+good(b);
  };
  auto rem = [&](int a, int b) {
    ans -= good(a)+good(b);
    node[a].erase(b);
    node[b].erase(a);
    ans += good(a)+good(b);
  };
  while (m--) {
    int a, b;
    cin >> a >> b;
    add(--a, --b);
  }

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b;
      cin >> a >> b;
      add(--a, --b);
    } else if (type == 2) {
      int a, b;
      cin >> a >> b;
      rem(--a, --b);
    } else {
      cout << ans << '\n';
    }
  }
}