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
    int n;
    cin >> n;
    ll sol = 0;
    map<int, ll> mp;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      sol += mp[x] * (n-i);
      mp[x] += i+1;
    }
    cout << sol << '\n';
  }
}