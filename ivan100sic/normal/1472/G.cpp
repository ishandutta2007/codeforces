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
    int n, m;
    cin >> n >> m;

    vector<basic_string<int>> e(n);

    for (int i=0; i<m; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      e[x] += y;
    }

    queue<int> q;
    q.push(0);
    vector<int> d(n, -1), d1;
    d[0] = 0;

    while (q.size()) {
      int x = q.front();
      q.pop();
      for (int y : e[x]) {
        if (d[y] == -1) {
          d[y] = d[x] + 1;
          q.push(y);
        }
      }
    }

    d1 = d;

    vector<int> o(n);
    iota(begin(o), end(o), 0);
    sort(begin(o), end(o), [&](int x, int y) { return d[x] > d[y]; });

    for (int x : o) {
      for (int y : e[x]) {
        if (d[y] > d[x]) {
          d1[x] = min(d1[x], d1[y]);
        } else {
          d1[x] = min(d1[x], d[y]);
        }
      }
    }

    for (int i=0; i<n; i++) {
      cout << d1[i] << " \n"[i == n-1];
    }

  }
}