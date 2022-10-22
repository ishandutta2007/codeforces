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
  set<int> s, done;
  vector<int> ans = {0};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > 0) {
      if (done.count(a)) fail();
      s.insert(a);
      done.insert(a);
    } else {
      a *= -1;
      if (!s.count(a)) fail();
      s.erase(a);
    }
    ans.back()++;
    if (i != n-1 && s.empty()) {
      ans.push_back(0);
      done.clear();
    }
  }
  if (s.size()) fail();
  cout << ans.size() << endl;
  for (int i : ans) cout << i << ' ';
  cout << endl;
}