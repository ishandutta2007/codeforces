#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  if (k > 4*w*h-w*2-h*2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  vector<pair<string, int>> ans;
  for (int i = 0; i < h-1; i++) {
    ans.emplace_back("R", w-1);
    ans.emplace_back("L", w-1);
    ans.emplace_back("D", 1);
  }
  for (int i = 0; i < w-1; i++) {
    ans.emplace_back("R", 1);
    ans.emplace_back("U", h-1);
    ans.emplace_back("D", h-1);
  }
  ans.emplace_back("L", w-1);
  ans.emplace_back("U", h-1);
  vector<pair<string,int>> filtered;
  for (auto [s,c] : ans) {
    assert(s.size() == 1);
    int steps = min(c, k);
    if (steps) {
      filtered.emplace_back(s, steps);
      k -= steps;
    }
  }
  cout << filtered.size() << endl;
  for (auto [s, c] : filtered)
    cout << c << ' ' << s << '\n';
}