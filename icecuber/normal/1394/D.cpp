#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
ll cost[nax], h[nax];

int ins[nax], outs[nax];

int done[nax];
ll ans = 0;

array<ll,2> dfs(int p, int par) {
  if (done[p]++) return {0,0};
  ll base = 0;
  vector<ll> add;
  for (int i : node[p]) {
    if (i == par) continue;
    auto [a,b] = dfs(i, p);
    base += a;
    add.push_back(b-a);
  }
  sort(add.begin(), add.end());
  auto calc = [&]() {
    ll best = 1e18;
    ll acc = base;
    int k = add.size();
    for (int i = 0; i <= k; i++) {
      best = min(best, acc+cost[p]*max(ins[p]+i, outs[p]+k-i));
      if (i < k)
	acc += add[i];
    }
    //cout << p << ": " << best << ' ' << ins[p] << ' ' << outs[p] << ' ' << (k ? add[0] : 0) << endl;
    return best;
  };
  if (par == -1) {
    ans += calc();
    return {0,0};
  } else {
    array<ll,2> ret;
    ins[p]++;
    ret[0] = calc();
    ins[p]--;
    outs[p]++;
    ret[1] = calc();
    outs[p]--;
    return ret;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cost[i];
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (h[a] < h[b]) outs[a]++, ins[b]++;
    else if (h[a] > h[b]) ins[a]++, outs[b]++;
    else {
      node[a].push_back(b);
      node[b].push_back(a);
    }
  }
  for (int i = 0; i < n; i++) dfs(i, -1);
  cout << ans << endl;
}