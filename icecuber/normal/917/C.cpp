#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cost[30][1<<8][1<<8];
int comp[256], icomp[256];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, k, n, q;
  cin >> x >> k >> n >> q;
  int c = 0;
  for (int i = 0; i < 256; i++) {
    if (__builtin_popcount(i) == x) {
      icomp[c] = i;
      comp[i] = c++;
    }
  }
  vector<ll> jmp_cost(k);
  for (ll&v : jmp_cost) cin >> v;

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++)
      cost[0][i][j] = 1e18;
    int m = icomp[i];
    int first = 0;
    while (!(m>>first&1)) first++;
    if (first > 0) {
      cost[0][i][comp[m>>1]] = 0;
    }
    for (int j = 1; j <= k; j++) {
      if (first+j <= 8 && !(m>>first+j&1)) {
	ll&ref = cost[0][i][comp[((m^1<<first) | 1<<first+j)>>1]];
	ref = min(ref, jmp_cost[j-1]);
      }
    }
  }

  for (int l = 0; l+1 < 30; l++) {
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < c; j++) {
	cost[l+1][i][j] = 1e18;
	for (int k = 0; k < c; k++) {
	  cost[l+1][i][j] = min(cost[l+1][i][j], cost[l][i][k]+cost[l][k][j]);
	}
      }
    }
  }

  auto step = [&](vector<ll> dp, int w) {
    int l = 0;
    while (w) {
      if (w&1) {
	vector<ll> ndp(c, 1e18);
	for (int i = 0; i < c; i++) {
	  for (int k = 0; k < c; k++) {
	    ndp[k] = min(ndp[k], dp[i]+cost[l][i][k]);
	  }
	}
	dp = ndp;
      }
      w >>= 1;
      l++;
    }
    return dp;
  };

  vector<ll> dp(c,1e18);
  dp[comp[(1<<x)-1]] = 0;

  map<int,ll> land_cost;
  vector<pair<int,ll>> stone;
  for (int i = 0; i < q; i++) {
    int p, w;
    cin >> p >> w;
    p--;
    stone.emplace_back(p,w);
    land_cost[p] = w;
  }
  sort(stone.begin(), stone.end());

  //#warning TODO
  //land_cost.clear();

  //12 201
  ll cur = 0;
  for (auto [p, w] : stone) {
    if (p-10 > cur) {
      dp = step(dp, p-10-cur);
      cur = p-10;
    }
    while (cur <= p && cur < n-x) {
      vector<ll> ndp(c,1e18);
      for (int i = 0; i < c; i++) {
	int m = icomp[i];
	int first = 0;
	while (!(m>>first&1)) first++;
	if (first > 0) {
	  ll&ref = ndp[comp[m>>1]];
	  ref = min(ref, dp[i]);
	}
	for (int j = 1; j <= k; j++) {
	  if (first+j <= 8 && !(m>>first+j&1)) {
	    ll&ref = ndp[comp[((m^1<<first) | 1<<first+j)>>1]];
	    ref = min(ref, dp[i]+jmp_cost[j-1]+land_cost[cur+j+first]);
	  }
	}
      }
      dp = ndp;
      cur++;
    }
  }
  //assert(cur == n-x);
  dp = step(dp, n-x-cur);
  cout << dp[comp[(1<<x)-1]] << endl;
}