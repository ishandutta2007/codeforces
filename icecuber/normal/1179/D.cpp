#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

vector<int> node[500000];

ll n;
ll dp[500000], sz[500000];
ll ans = 1e18;
ll f(ll n) {return n*(n+1)/2;}
void dfs(int p, int par = -1) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p);
    sz[p] += sz[i];
  }
  dp[p] = f(sz[p]);

  vector<pair<ll,ll>> v;
  for (int i : node[p]) {
    if (i == par) continue;
    dp[p] = min(dp[p], f(sz[p]-sz[i])+dp[i]);
    v.emplace_back(sz[i], dp[i]*2+sz[i]*sz[i]);
  }
  sort(v.begin(), v.end());

  vector<double> xs;
  vector<pair<ll,ll>> s;
  xs.push_back(-1e18);
  s.emplace_back(0,0);
  auto cross = [&](pair<ll,ll> a, pair<ll,ll> b) {
    assert(a.x != b.x);
    return max(-double(a.y-b.y)/(a.x-b.x),-0.9e18);
  };
  auto query = [&](ll x) {
    int i = upper_bound(xs.begin(), xs.end(), (double)x)-xs.begin()-1;
    return s[i].x*x+s[i].y;
  };
  auto append = [&](ll a, ll b) {
    pair<ll,ll> m(a,b);
    assert(m.x <= s.back().x);
    if (m.x == s.back().x) {
      assert(s.size() > 1);
      if (s.back().y < m.y) return;
      s.pop_back();
      xs.pop_back();
    }
    assert(s.size() == xs.size());
    while (cross(s.back(), m) <= xs.back()) s.pop_back(), xs.pop_back();
    xs.push_back(cross(s.back(), m));
    s.push_back(m);
  };
  for (auto v : v) {
    ll n_ = n-v.x;
    ll score = v.y+n*n+n-(2*n+1)*v.x+query(2*n_+1);
    ans = min(ans, score/2);
    append(-v.x, v.y);
  }
  /*for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < i; j++) {
      ll score = f(n-v[i].x-v[j].x)+v[i].y+v[j].y;
      ans = min(ans, score);
    }
    }*/
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  cout << n*n-ans << endl;
}