#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int,int> need;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      int p = 0;
      while (a) {
	need[p] += a%k;
	a /= k;
	p++;
      }
    }
    int ok = 1;
    for (auto [p,v] : need)
      if (v > 1) ok = 0;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}