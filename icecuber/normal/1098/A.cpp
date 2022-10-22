#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> child[100000];
ll a[100000], p[100000], s[100000], mi[100000];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    child[p[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mi[i] = 2e9;
  }
  ll ans = 0;
  for (int i = n-1; i >= 0; i--) {
    if (s[p[p[i]]] > s[i] && s[i] != -1) {
      cout << -1 << endl;
      return 0;
    }
    if (s[i] != -1) {
      if (i)
	mi[p[i]] = min(mi[p[i]], s[i]-s[p[p[i]]]);
      else ans += s[i];
    } else {
      a[i] = mi[i] == 2e9 ? 0 : mi[i];
      ans += a[i];
      for (int j : child[i]) {
	a[j] = s[j]-s[p[i]]-a[i];
	ans += a[j];
      }
    }
  }
  cout << ans << endl;
}