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
    vector<ll> a(n), b(n);
    ll balance = 0;
    for (ll&v : a) cin >> v, balance += v;
    for (ll&v : b) cin >> v, balance -= v;
    ll worst = 0, ok = 1;
    for (int i = 1; i < n*2; i++) {
      worst = max(0ll, worst)+a[i%n]-b[(i-1)%n];
      if (worst > b[i%n]) ok = 0;
    }
    cout << (balance > 0 || ok == 0 ? "NO" : "YES") << endl;
  }
}