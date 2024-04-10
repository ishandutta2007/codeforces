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
    int n, k, m;
    cin >> n >> k >> m;
    k--;
    vector<int> u(n);
    for (int i=0; i<m; i++) {
      int x;
      cin >> x;
      x--;
      u[x] = 1;
    }

    if ((n-m) % k) {
      cout << "NO\n";
      continue;
    }

    vector<int> e;
    for (int i=0; i<n; i++) {
      if (u[i] == 0) {
        e.push_back(i);
      }
    }

    int l = e[k/2-1];
    int r = e[e.size() - k/2];
    if (count(u.begin()+l+1, u.begin()+r, 1) == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}