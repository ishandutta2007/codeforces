#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<string> seen;
  string ans;
  string palin;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());
    if (r == s) palin = s;
    else if (seen.count(r)) {
      ans += r;
    }
    seen.insert(s);
  }
  string rans = ans;
  reverse(rans.begin(), rans.end());
  cout << ans.size()*2+palin.size() << endl;
  cout << ans << palin << rans << endl;
}