#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll x, k, y;
  cin >> x >> k >> y;
  vector<int> a(n), b(m);
  vector<int> ai(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    ai[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
    if (ai[b[i]] == -1) assert(0);
  }
  auto f = [&](int l, int r)  {
    if (l >= r) fail();
    vector<int> v;
    for (int i = l; i <= r; i++) {
      if (i == -1 || i == n) v.push_back(-1);
      else v.push_back(a[i]);
    }
    int w = v.size()-2;
    int thres = max(v[0], v.back());
    int need = 0;
    for (int i = 0; i < w; i++) {
      int bad = (v[i+1] > thres);
      if (bad) {
	need = 1;
	i += k-1;
      }
    }
    if (need*k > w) fail();
    return min(need*x+(w-need*k)*y, w/k*x+w%k*y);
  };
  ll ans = 0;
  ans += f(-1, ai[b[0]]);
  for (int i = 0; i+1 < m; i++) {
    ans += f(ai[b[i]], ai[b[i+1]]);
  }
  ans += f(ai[b[m-1]], n);
  cout << ans << endl;
}