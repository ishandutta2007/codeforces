#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  vector<pair<char,int>> v;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == '0' && v.size() && v.back().x == '1')
      v.pop_back();
    else v.push_back({c,i});
  }
  string ans = s;
  for (auto p : v)
    ans[p.y] = '0';
  cout << ans << endl;
}