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
    for (int&v : a) cin >> v;
    sort(a.rbegin(), a.rend());
    a.resize(unique(a.begin(), a.end())-a.begin());
    int ans = 0;
    for (int k = 0; k < 20 && k < n; k++) {
      int score = 0;
      vector<int> v;
      for (int i : a) {
	int ok = i;
	for (int j : v) if (j%i == 0) ok = 0;
	if (ok) {
	  v.push_back(i);
	  score += i;
	  if (v.size() == 3) break;
	}
      }
      ans = max(ans, score);
      a[k] = 0;
    }
    cout << ans << endl;
  }
}