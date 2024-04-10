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
    sort(begin(a), end(a), [](int x, int y) { return x % 2 < y % 2; });
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}