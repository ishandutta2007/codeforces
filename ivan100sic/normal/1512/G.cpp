// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  const int n = 1e7;
  vector<int> s(n+1), a(n+1, -1);
  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j+=i) {
      s[j] += i;
    }
  }

  for (int i=1; i<=n; i++) {
    if (s[i] <= n && a[s[i]] == -1) {
      a[s[i]] = i;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << a[x] << "\n";
  }
}