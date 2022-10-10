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
    sort(begin(a), end(a));
    int k = lower_bound(begin(a), end(a), 1) - a.begin();
    if (k == n) {
      cout << n << '\n';
    } else {
      int ok = 1;
      for (int i=0; i<k-1; i++) {
        if (a[i+1] - a[i] < a[k]) {
          ok = 0;
        }
      }
      cout << k + ok << '\n';
    }
  }
}