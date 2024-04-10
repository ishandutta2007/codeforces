#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll add(ll a, ll b) {
  return min((ll)2e18, a+b);
}
ll mul(ll a, ll b) {
  if ((ld)a * b > 4e18) return 2e18;
  return min((ll)2e18, a*b);
}

const int nax = 60;
ll g[nax];
ll mem[nax];
ll f(int n) {
  if (n <= 1) return 1;
  if (!mem[n]) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans = add(ans, mul(g[i], f(n-i-1)));
    }
    mem[n] = ans;
  }
  return mem[n];
}


int main() {
  g[0] = g[1] = 1;
  for (int i = 2; i < nax; i++) {
    g[i] = mul(g[i-1], i-1);
  }

  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    k--;

    if (f(n) <= k) {
      cout << -1 << endl;
      continue;
    }

    vector<int> p(n, -1);

    int ma = -1;
    ll ind = 0;
    set<int> left;
    map<int,int> par;

    function<int(int)> find = [&](int p) {
      return par[p] == p ? p : par[p] = find(par[p]);
    };
    for (int i = 0; i < n; i++) {
       if (left.empty()) {
	ma = -1;
	for (int j = i; j < n; j++) {
	  ll cp = ind;
	  ind = add(ind, mul(g[j-i], f(n-j-1)));
	  if (ind > k) {
	    ma = j;
	    ind = cp;
	    break;
	  }
	}
	par.clear();
	for (int j = i; j <= ma; j++) {
	  left.insert(j);
	  par[j] = j;
	}

	p[i] = ma;
	assert(ma != -1);

      } else {
	for (int j : left) {
	  if (find(j) == i) continue;
	  int ls = left.size();
	  ll cp = ind;
	  ind = add(ind, mul( g[ls-1], f(n-ma-1)));
	  if (ind > k) {
	    ind = cp;
	    p[i] = j;
	    break;
	  }
	}
	assert(p[i] != -1);
      }
      assert(ind <= k);
      assert(p[i] != -1);

      //cout << p[i] << ' ' << k-ind << endl;
      if (p[i] != ma) {
	par[i] = par[p[i]];
      }
      assert(left.count(p[i]));
      left.erase(p[i]);
    }
    assert(ind == k);

    for (int v : p) cout << v+1 << ' ';
    cout << endl;

    for (int i = 0; i < n; i++) {
      int j = i, ma = -1, cnt = 0;
      do {
	cnt++;
	j = p[j];
	ma = max(ma, j);
      } while (j != i);
      assert(cnt == ma-i+1);
      i = ma;
    }
  }
}