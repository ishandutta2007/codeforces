#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vint a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vpii ans;
  set<int> ys;
  set<pii> rs, cs;
  for(int i = n; i >= 1; i--) {
    if(a[i] == 0) continue;
    else if(a[i] == 1) {
      ans.emplace_back(i, i);
      ys.insert(i);
      rs.emplace(i, i);
      cs.emplace(i, i);
    }
    else if(a[i] == 2) {
      if(rs.empty()) { cout << "-1\n"; return 0; }
      pii t = *rs.begin();
      rs.erase(t);
      cs.erase(t);

      ans.emplace_back(i, t.y);
      cs.emplace(i, t.y);
    }
    else {
      if(cs.empty()) { cout << "-1\n"; return 0; }
      pii t = *cs.begin();
      rs.erase(t);
      cs.erase(t);

      ans.emplace_back(i, i);
      ans.emplace_back(t.x, i);
      ys.insert(i);
      cs.emplace(i, i);
    }
  }

  vint yss;
  for(int x : ys) yss.push_back(x);
  for(pii &p : ans) {
    p.y = int(lower_bound(all(yss), p.y) - yss.begin()) + 1;
  }

  cout << ans.size() << '\n';
  for(pii &p : ans) cout << p.y << ' ' << p.x << '\n';
  return 0;
}