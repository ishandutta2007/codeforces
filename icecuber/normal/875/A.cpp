#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int s = 0; s < 1000; s++) {
    int x = n-s;
    if (x < 0) continue;
    string v = to_string(x);
    int xsum = 0;
    for (char c : v) xsum += c-'0';
    if (xsum == s) ans.push_back(x);
  }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i << '\n';
}