// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef vector<char> vb;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int& x : a) cin >> x;

    vector<int> pm = {0}, v;
    for (int i=1; i<2*n; i++) {
      if (a[i] > a[pm.back()]) {
        pm.push_back(i);
      }
    }

    pm.push_back(2*n);
    for (int i=0; i<(int)pm.size()-1; i++) {
      v.push_back(pm[i+1] - pm[i]);
    }

    vb d(2*n+1);
    d[0] = 1;
    for (int w : v) {
      for (int i=2*n; i>=w; i--) {
        d[i] |= d[i-w];
      }
    }

    cout << (d[n] ? "YES\n" : "NO\n");
  }
}