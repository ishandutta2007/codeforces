#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char,vector<int>> f() {
  string s;
  cin >> s;
  map<char,vector<int>> ans;
  int i = 1;
  for (char c : s)
    ans[c].push_back(i++);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<char,vector<int>> a = f(), b = f();
  vector<pair<int,int>> ans;
  for (auto p : a) {
    char c = p.first;
    if (c == '?') continue;
    while (a[c].size() && b[c].size()) {
      ans.push_back({a[c].back(),b[c].back()});
      a[c].pop_back();
      b[c].pop_back();
    }
  }
  while (a['?'].size()) {
    int found = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      if (b[c].size()) {
	ans.push_back({a['?'].back(),b[c].back()});
	a['?'].pop_back();
	b[c].pop_back();
	found = 1;
	break;
      }
    }
    if (!found) break;
  }
  while (b['?'].size()) {
    int found = 0;
    for (char c = 'a'; c <= 'z'+1; c++) {
      if (c == 'z'+1) c = '?';
      if (a[c].size()) {
	ans.push_back({a[c].back(),b['?'].back()});
	a[c].pop_back();
	b['?'].pop_back();
	found = 1;
	break;
      }
      if (c == '?') break;
    }
    if (!found) break;
  }
  cout << ans.size() << endl;
  for (auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}