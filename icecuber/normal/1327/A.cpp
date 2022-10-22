#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    if (n%2 != k%2 || n < k*k) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}