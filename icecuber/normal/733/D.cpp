#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void umax(T&a, T b) {
  a = max(a, b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<pair<int,int>, pair<int,int>> m;
  int best = -1;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    {
      int score = min({a,b,c});
      if (score > best) best = score, ans = {i};
    }
    if (m.count({a,b})) {
      auto [nc,ni] = m[{a, b}];
      int score = min({a,b,nc+c});
      if (score > best) best = score, ans = {i, ni};
    }
    if (m.count({a,c})) {
      auto [nb,ni] = m[{a, c}];
      int score = min({a,b+nb,c});
      if (score > best) best = score, ans = {i, ni};
    }
    if (m.count({b,c})) {
      auto [na,ni] = m[{b, c}];
      int score = min({na+a,b,c});
      if (score > best) best = score, ans = {i, ni};
    }
    umax(m[{a, b}], {c, i});
    umax(m[{a, c}], {b, i});
    umax(m[{b, c}], {a, i});
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i+1 << ' ';
  cout << endl;
}