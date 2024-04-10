// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void rek(vector<int>& a, int l, int r, vector<ll>& v) {
  if (l >= r) return;
  v.push_back(accumulate(begin(a)+l, begin(a)+r, 0ll));
  int x = (a[l] + a[r-1]) / 2;
  int m = lower_bound(begin(a)+l, begin(a)+r, x+1) - begin(a);
  if (l == m || m == r) return;
  rek(a, l, m, v);
  rek(a, m, r, v);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> v;
    for (int& x : a) cin >> x;

    sort(begin(a), end(a));
    rek(a, 0, n, v);

    sort(begin(v), end(v));

    while (q--) {
      int x;
      cin >> x;
      auto it = lower_bound(begin(v), end(v), x);
      if (it != end(v) && *it == x) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}