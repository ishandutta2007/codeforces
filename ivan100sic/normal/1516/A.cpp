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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    
    for (int i=0; i<k; i++) {
      auto j = find_if(begin(a), end(a), [](int x) { return x > 0; }) - begin(a);
      if (j >= n-1) {
        break;
      }
      a[j]--;
      a[n-1]++;
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
  }
}