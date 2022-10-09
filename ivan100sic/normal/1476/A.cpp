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
    ll n, k;
    cin >> n >> k;

    if (n > k && n % k) {
      cout << "2\n";
    } else {
      cout << (k+n-1)/n << '\n';
    }
  }
}