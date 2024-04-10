#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> ans;
ll rec(ll mi, ll ma, ll goal, ll m) {
  if (mi >= goal) return -1;
  if (mi+1 <= goal && goal <= ma+m) {
    ans.push_back(goal);
    return max(goal-m, mi);
  }
  ll y = rec(mi*2+1, ma*2+m, goal, m);
  if (y == -1) return -1;
  assert(y >= mi*2+1 && y <= ma*2+m);
  ll y_ = max(mi, (y-m+1)/2);
  ans.push_back(y-y_);
  return y_;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, m;
    cin >> a >> b >> m;
    ans.clear();
    if (rec(a, a, b, m) == -1 && a != b)
      cout << -1 << endl;
    else {
      ans.push_back(a);
      reverse(ans.begin(), ans.end());
      cout << ans.size() << ' ';
      for (ll v : ans)
	cout << v << ' ';
      cout << endl;
    }
  }
}