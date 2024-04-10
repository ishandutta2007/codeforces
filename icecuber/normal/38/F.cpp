#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

map<string, pair<int,pair<int,int>>> mem;
map<string,int> allowed;

pair<int,pair<int,int>> rec(string cur, int sum = 0, int ma = 0) {
  if (mem.count(cur)) return mem[cur];
  auto&ans = mem[cur];
  for (char c = 'a'; c <= 'z'; c++) {
    int val = c-'a'+1;
    int new_sum = sum+val;
    int new_ma = max(ma, val);
    for (string s : {cur+c, c+cur}) {
      auto it = allowed.find(s);
      if (it == allowed.end()) continue;

      int score = new_sum*new_ma+it->second;
      auto cont = rec(s, new_sum, new_ma);
      ans = max(ans, {!cont.x, {-cont.y.y+score, -cont.y.x}});
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    set<string> substrings;
    for (int l = 0; l < s.size(); l++)
      for (int w = 1; w+l <= s.size(); w++)
	substrings.insert(s.substr(l,w));
    for (string sub : substrings)
	allowed[sub]++;
  }
  auto ans = rec("");
  cout << (ans.x ? "First" : "Second") << endl;
  cout << ans.y.x << ' ' << -ans.y.y << endl;
}