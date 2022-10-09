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
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int w = r-l+1;
    if (s < w*(w+1)/2 || s > w*(2*n+1-w) / 2) {
      cout << "-1\n";
      continue;
    }

    vector<int> a(n);
    iota(begin(a), end(a), 1);
    s -= w*(w+1)/2;
    for (int i=w-1; i>=0; i--) {
      while (s > 0 && a[i] < n-w+i+1) {
        s--;
        a[i]++;
      }
    }

    set<int> u;
    for (int i=1; i<=n; i++) {
      u.insert(i);
    }

    for (int i=0; i<w; i++) {
      u.erase(a[i]);
    }

    for (int i=w; i<n; i++) {
      a[i] = *u.begin();
      u.erase(u.begin());
    }

    rotate(a.begin(), a.end()-(l-1), a.end());

    for (int i=0; i<n; i++) {
      cout << a[i] << " \n"[i == n-1];
    }
  }
}