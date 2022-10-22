#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(string a, string b) {
  //cout << a << ' ' << b << endl;
  string ans;
  int i = 0, j = 0;
  int na = a.size(), nb = b.size();
  while (i < na || j < nb) {
    if (i < na && a[i] == '1') ans += a[i++];
    else if (j < nb && b[j] == '1') ans += b[j++];
    else if (i < na && j < nb && a[i] == '0' && b[j] == '0') {
      ans += a[i++];
      j++;
    } else if (i < na) {
      assert(j == nb);
      ans += a[i++];
    } else if (j < nb) {
      assert(i == na);
      ans += b[j++];
    } else assert(0);
  }
  assert((int)ans.size() <= na/2*3);
  while ((int)ans.size() < na/2*3) ans += '0';
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    vector<string> v[2];
    for (string r : s) {
      int c = count(r.begin(), r.end(), '0');
      v[c < n].push_back(r);
    }
    string ans;
    if (v[0].size() >= 2) {
      ans = f(v[0][0], v[0][1]);
    } else {
      for (char&c : v[1][0]) c ^= 1;
      for (char&c : v[1][1]) c ^= 1;
      ans = f(v[1][0], v[1][1]);
      for (char&c : ans) c ^= 1;
    }
    cout << ans << endl;
  }
}