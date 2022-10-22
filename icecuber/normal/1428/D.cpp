#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> twos, threes;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  vector<array<int,2>> ans;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == 0) continue;
    else if (a[i] == 1) {
      ans.push_back({i,i});
      twos.push_back(i);
    } else if (a[i] == 2) {
      if (twos.empty()) fail();
      int y = twos.back();
      twos.pop_back();

      ans.push_back({i,y});

      threes.push_back(i);
    } else if (a[i] == 3) {
      if (threes.empty() && twos.empty()) fail();

      int y;
      if (threes.size()) {
	y = threes.back();
	threes.pop_back();
      } else {
	y = twos.back();
	twos.pop_back();
      }

      ans.push_back({i,i});
      ans.push_back({y,i});

      threes.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (auto [x,y] : ans) cout << y+1 << ' ' << x+1 << endl;
}