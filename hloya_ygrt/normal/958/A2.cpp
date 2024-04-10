#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<string> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  vector<pair<vector<string>, int> > a, b;
  for (int i = 0; i + m - 1 < n; i++) {
    vector<string> cur;
    for (int j = 0; j < m; j++) {
      cur.emplace_back(s[i + j]);
    }
    a.emplace_back(cur, i);
    cur.clear();
    for (int j = 0; j < m; j++) {
      // now j is row, i is column
      string cur_s;
      for (int q = 0; q < m; q++) {
        cur_s += t[j][i + q];
      }
      cur.emplace_back(cur_s);
    }
    b.emplace_back(cur, i);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ptr = 0;
  for (int i = 0; i < (int) b.size(); i++) {
    while (ptr < (int) a.size() && a[ptr].first < b[i].first) {
      ptr++;
    }
    if (ptr < (int) a.size() && a[ptr].first == b[i].first) {
      printf("%d %d\n", a[ptr].second + 1, b[i].second + 1);
      return 0;
    }
  }
  assert(0);
  return 0;  
}