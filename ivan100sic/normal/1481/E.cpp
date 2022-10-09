// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[500005], c[500005], e[500005];
int l[500005], r[500005], d[500005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<=n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (l[x] == 0) {
      l[x] = i;
    }

    r[x] = i;
    c[x]++;
  }

  for (int i=1; i<=n; i++) {
    int x = a[i];
    if (l[x] == i) {
      d[r[x]] = max(d[r[x]], d[i-1] + c[x]);
    }
    d[i] = max(d[i], d[i-1]);
  }

  int sol = n - d[n];
  for (int i=n; i>=1; i--) {
    int fc = ++e[a[i]];
    sol = min(sol, n - (d[i-1] + fc));
  }

  cout << sol << '\n';
}