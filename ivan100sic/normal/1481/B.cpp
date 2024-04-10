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
    int n, k, ans = -1;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int i=0; i<k; i++) {
      int j = -1;
      for (int i=0; i<n-1; i++) {
        if (a[i] < a[i+1]) {
          j = i;
          break;
        }
      }

      if (j == -1) {
        ans = -1;
        break;
      } else {
        a[j]++;
        ans = j + 1;
      }
    }

    cout << ans << '\n';
  }
}