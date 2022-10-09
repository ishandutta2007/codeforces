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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    auto [l, r] = minmax_element(begin(a), end(a));
    int i = l - a.begin();
    int j = r - a.begin();
    cout << min({max(i, j) + 1, max(n-i, n-j), min(i, j) + 1 + n - max(i, j)}) << '\n';
  }
}