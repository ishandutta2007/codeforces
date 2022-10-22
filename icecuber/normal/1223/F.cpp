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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> sz(n+1);
    vector<map<int,int>> m(n+1);
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (m[i+1].count(a[i])) {
	int j = m[i+1][a[i]];
	assert(a[j] == a[i]);
	m[i] = move(m[j+1]);
	sz[i] = sz[j+1]+1;
      }
      m[i][a[i]] = i;
      ans += sz[i];
    }
    cout << ans << endl;
  }
}