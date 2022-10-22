#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Interval {
  int mi, ma;
  Interval() {
    ma = -1e9, mi = 1e9;
  }
  void add(int x) {
    ma = max(ma, x);
    mi = min(mi, x);
  }
  void add(Interval o) {
    ma = max(ma, o.ma);
    mi = min(mi, o.mi);
  }
};

ll solve(vector<Interval>&v) {
  int w = v.size();
  vector<Interval> pref(w);
  for (int i = 0; i < w; i++) {
    if (i)
      pref[i] = pref[i-1];
    pref[i].add(v[i]);
  }
  Interval post;
  ll ans = 0;
  for (int i = w-1; i >= 1; i--) {
    post.add(v[i]);
    int d = min(pref[i-1].ma, post.ma)-max(pref[i-1].mi, post.mi);
    if (d > 0) ans += d;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int w = 1e5;
  vector<vector<Interval>> v(2,vector<Interval>(w*2));
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x+y&1][x-y+w*2>>1].add(x+y+w*2>>1);
  }
  cout << solve(v[0])+solve(v[1]) << endl;
}