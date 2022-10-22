#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segTree {
  ll*data;
  int n;
  segTree(int n) : n(n) {
    data = new ll[n*2]();
  }
  void add(int i, ll v) {
    for (i += n; i; i >>= 1) data[i] += v;
  }
  int find(ll v) {
    int i = 1;
    while (i < n) {
      i *= 2;
      if (v >= data[i]) v -= data[i++];
    }
    return i-n;
  }
  ll sum(int i) {
    ll r = data[i+n];
    for (i += n; i > 1; i >>= 1) {
      if (i&1)
	r += data[i-1];
    }
    return r;
  }
};

segTree count_tree(1<<17), sum_tree(1<<17);

ll x[100000], t[100000];
vector<pair<int,ll>> child[100000];

map<int,int> ti_map;
int ti_list[100000];
ll dp[100000], dp2[100000];
void dfs(int p, ll T) {
  if (T <= 0) return;
  count_tree.add(ti_map[t[p]], x[p]);
  sum_tree.add(ti_map[t[p]], x[p]*t[p]);

  int i = sum_tree.find(T);
  dp[p] = count_tree.sum(i-1);
  assert(sum_tree.sum(i-1) <= T);

  //cout << p+1 << ' ' << count_tree.sum((1<<17)-1) << endl;
  //for (int i = 0; i < 10; i++)
  //  cout << sum_tree.data[sum_tree.n+i] << ' ';
  //cout << endl;
  //cout << sum_tree.sum(i-1) << ' ' << T << ' ' << sum_tree.sum(i) << ' ' << i << ' ' << sum_tree.sum((1<<17)-1) << endl;
  assert(i >= 1e5+10 || sum_tree.sum(i) > T);
  if (i < 1e5+10) dp[p] += (T-sum_tree.sum(i-1))/ti_list[i];
  vector<ll> child_vals;
  for (auto e : child[p]) {
    dfs(e.first, T-e.second*2);
    child_vals.push_back(dp2[e.first]);
  }
  sort(child_vals.rbegin(), child_vals.rend());
  dp2[p] = dp[p];
  if (child_vals.size() >= 2)
    dp2[p] = max(dp2[p], child_vals[1]);
  if (p == 0)
    dp2[p] = max(dp2[p], child_vals[0]);

  count_tree.add(ti_map[t[p]], -x[p]);
  sum_tree.add(ti_map[t[p]], -x[p]*t[p]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, T;
  cin >> n >> T;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    ti_map[t[i]];
  }

  int c = 1;
  for (auto&p : ti_map) {
    ti_list[c] = p.first;
    p.second = c++;
  }

  for (int i = 1; i < n; i++) {
    ll p, l;
    cin >> p >> l;
    child[p-1].push_back({i,l});
  }
  dfs(0,T);
  cout << dp2[0] << endl;
}