#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string,int> query(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int n = (r-l)+1;
  map<string,int> ret;
  for (int i = 0; i < n*(n+1)/2; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ret[s]++;
  }
  return ret;
}

int cnt[101][26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  auto a = query(1, n);
  if (n == 1) {
    cout << "! " << a.begin()->first[0] << endl;
    return 0;
  }
  auto b = query(2, n);
  for (auto p : b) {
    a[p.first] -= p.second;
  }

  for (auto p : a) {
    if (p.second) {
      int l = p.first.size();
      for (char i : p.first)
	cnt[l][i-'a']++;
    }
  }
  string ans;
  ans.resize(n);
  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 26; c++)
      if (cnt[i][c] > cnt[i-1][c])
	ans[i-1] = c+'a';
  }
  cout << "! " << ans << endl;
}