// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

basic_string<int> e[200005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  for (int i=1; i<=200000; i++) {
    for (int j=i; j<=200000; j+=i) {
      e[j] += i;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> s(200005, -123123123), a(n);
    s[1] = 0;

    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    sort(begin(a), end(a));

    for (int x : a) {
      int z = -123123123;
      for (int y : e[x]) {
        z = max(z, s[y]);
      }
      s[x] = z + 1;
    }

    cout << n - *max_element(begin(s), end(s)) << '\n';
  }
}