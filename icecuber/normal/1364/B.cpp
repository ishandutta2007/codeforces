#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sign(int x) {
  return x > 0 ? 1 : -1;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (ans.size() >= 2 && sign(ans.end()[-2]-ans.end()[-1]) == sign(ans.back()-p))
	ans.pop_back();
      ans.push_back(p);
    }
    cout << ans.size() << endl;
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}