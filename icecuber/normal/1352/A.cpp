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
    vector<int> ans;
    int mul = 1;
    while (n) {
      mul *= 10;
      if (n%mul)
	ans.push_back(n%mul);
      n -= n%mul;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}