#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> a(1);
  for (char c : s) a[0].push_back(c-'a');
  for (int k = 0; k < n; k++) {
    vector<array<int,2>> m;
    for (auto v : a) {
      for (int i = 0; i < (int)v.size(); i += 2) {
        m.push_back({v[i],v[i+1]});
        m.push_back({v[i+1],v[i]});
      }
    }
    sort(m.begin(), m.end());
    vector<vector<int>> A,B;
    for (auto v : a) {
      vector<int> na, nb;
      for (int i = 0; i < (int)v.size(); i += 2) {
        na.push_back(lower_bound(m.begin(), m.end(), array<int,2>{v[i],v[i+1]})-m.begin());
        nb.push_back(lower_bound(m.begin(), m.end(), array<int,2>{v[i+1],v[i]})-m.begin());
      }
      A.push_back(na);
      B.push_back(nb);
    }
    a = A;
    for (auto x : B) a.push_back(x);
  }
  for (int i = 0; i < 1<<n; i++) {
    if (a[i][0] == 0) {
      for (int j = 0; j < 1<<n; j++) {
        cout << s[i^j];
      }
      cout << endl;
      return 0;
    }
  }
}