#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> ai(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a--;
      ai[a] = i;
    }
    int last = -1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      b--;
      int p = ai[b];
      if (p > last)
	ans += p*2+1-i*2;
      else
	ans++;
      last = max(last, p);
    }
    cout << ans << endl;
  }
}