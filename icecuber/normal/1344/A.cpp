#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<ll> land;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      land.insert(((i+a)%n+n)%n);
    }
    cout << (land.size() == n ? "YES" : "NO") << endl;
  }
}