// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, q, k;
int a[100005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> q >> k;

  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << -2*(r-l+1) + 1 - a[l] + a[r] + k << '\n';
  }
}