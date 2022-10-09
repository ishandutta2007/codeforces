// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    vector<basic_string<int>> e(n+2);
    for (int i=0; i<n; i++) {
      cin >> a[i];
      e[a[i]] += i;
    }

    int ph = find_if(begin(e)+1, end(e), [](auto& x) { return x.empty(); })
      - begin(e);

    set<pair<int, int>> ss;
    for (int i=1; i<=n+1; i++) {
      ss.emplace(e[i].size(), i);
    }
    vector<int> sol(n, -1);

    for (int i=0; i<x; i++) {
      auto it = prev(ss.end());
      auto [sz, val] = *it;
      ss.erase(it);

      int b = e[val].back();
      e[val].pop_back();
      sol[b] = val;

      sz--;
      ss.emplace(sz, val);
    }

    int deplace = 0;
    if (x < n) {
      int w = prev(ss.end())->first;
      if (2*w > n-x) {
        deplace = (n-x-w)*2;
      } else {
        deplace = n-x;
      }
    }

    if (deplace < y-x) {
      cout << "NO\n";
      continue;
    }

    int td = deplace;
    vector<int> rot;
    for (auto [sz, val] : ss) {
      for (int i : e[val]) {
        if (td > 0) {
          td--;
          rot.push_back(i);
        }
      }
    }

    for (int i=0; i<y-x; i++) {
      sol[rot[i]] = a[rot[(i+deplace/2) % deplace]];
    }

    for (int& x : sol) if (x == -1) x = ph;

    cout << "YES\n";
    for (int x : sol) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}