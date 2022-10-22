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
  /*{
    for (int n = 1; n <= 100; n++) {
      int a = (n+1)/2, b = a-1, c = n;
      assert(a*(a+1)/2 + b*(b+1)/2 + c*(c+1)/2 <= ceil(0.777 * (n+1) * (n+1)));
    }
  }
  cout << "OK" <<endl;
  return 0;*/
  int n;
  cin >> n;
  auto full = query(1, n);
  if (n == 1) {
    cout << "! " << full.begin()->first[0] << endl;
    return 0;
  }

  int l = (n+1)/2;
  auto a = query(1, l);

  string ans;
  ans.resize(n);

  if (l == 1) {
    ans[0] = a.begin()->first[0];
  } else {
    auto b = query(2, l);

    for (auto p : b) {
      a[p.first] -= p.second;
    }

    for (auto p : a) {
      if (p.second) {
	int len = p.first.size();
	for (char i : p.first)
	  cnt[len][i-'a']++;
      }
    }

    for (int i = 1; i <= l; i++) {
      for (int c = 0; c < 26; c++)
	if (cnt[i][c] > cnt[i-1][c])
	  ans[i-1] = c+'a';
    }
  }

  int tot[26] = {};
  for (auto [s,c] : full) {
    if (s.size() == n) {
      assert(c == 1);
      for (char i : s)
	tot[i-'a']++;
    }
  }

  for (int p = n-1; p >= l; p--) {
    int w = p;
    multiset<string> left;
    for (auto [s,c] : full) {
      if (s.size() == w) {
	for (int i = 0; i < c; i++)
	  left.insert(s);
      }
    }
    for (int i = 1; i+w <= n; i++) {
      assert(i <= l);
      int c[26];
      copy_n(tot, 26, c);
      for (int j = 0; j < n; j++) {
	if (j >= i && j < i+w) continue;
	c[ans[j]-'a']--;
      }
      string s;
      for (int ci = 0; ci < 26; ci++)
	for (int j = 0; j < c[ci]; j++)
	  s += ci+'a';
      left.erase(left.find(s));
    }
    assert(left.size() == 1);

    {
      string s = *left.begin();
      int c[26];
      copy_n(tot, 26, c);
      for (char i : s) c[i-'a']--;
      for (int j = p+1; j < n; j++) {
	c[ans[j]-'a']--;
      }
      for (int i = 0; i < 26; i++)
	if (c[i]) ans[p] = i+'a';
    }
  }
  cout << "! " << ans << endl;
}