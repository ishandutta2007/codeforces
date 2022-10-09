// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, q;
int a[300005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> q;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }

  while (q--) {
    int t;
    cin >> t;
    int f = find(a+1, a+n+1, t) - a;
    cout << f << ' ';
    rotate(a+1, a+f, a+f+1);
  }
  cout << '\n';
}