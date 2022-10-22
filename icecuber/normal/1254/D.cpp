#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<18;
vector<int> node[nax];
int ai[nax], bi[nax];
int parent[nax];
int sz[nax];


const ll mod = 998244353;
ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int t = 0;
void dfs(int p, int par = -1) {
  parent[p] = par;
  sz[p] = 1;
  ai[p] = t++;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p);
    sz[p] += sz[i];
  }
  bi[p] = t;
}

//#warning Change B to ~300
const int B = 300;
int big[nax];

ll big_val[nax];
vector<int> big_list[nax];
vector<ll> big_weight[nax];
vector<int> big_ind[nax];

ll tree[nax];
void add(int i, int v) {
  v = (v%mod+mod)%mod;
  for (i += 5; i < nax; i += i&-i) {
    tree[i] += v;
    if (tree[i] >= mod)
      tree[i] -= mod;
  }
}
ll sum(int i) {
  ll r = 0;
  for (i += 5; i; i -= i&-i) {
    r += tree[i];
    if (r >= mod) r -= mod;
  }
  return r;
}

void add(int l, int r, ll v) {
  add(l,v);
  add(r,-v);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);

  ll in = bin_pow(n, mod-2);

  vector<int> bigs;
  for (int i = 0; i < n; i++) {
    if (node[i].size() >= B) {
      big[i] = 1;
      bigs.push_back(i);
      for (int j : node[i]) {
	if (j == parent[i]) continue;
	assert(big_list[i].empty() || big_list[i].back() < bi[j]);
	big_list[i].push_back(bi[j]);
	big_weight[i].push_back((n-sz[j])*in%mod);
	big_ind[i].push_back(j);
      }
    }
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, d;
      cin >> v >> d;
      v--;
      if (big[v]) {
	(big_val[v] += d) %= mod;
      } else {
	add(0, n, d);
	for (int i : node[v]) {
	  if (i == parent[v]) {
	    ll val = - (n-sz[v]) * in % mod * d % mod;
	    add(0, n, val);
	    add(ai[v],bi[v], -val);
	  } else {
	    add(ai[i],bi[i], - sz[i] * in % mod * d % mod);
	  }
	}
      }
    } else {
      assert(type == 2);
      int v;
      cin >> v;
      v--;

      ll ans = sum(ai[v]);
      for (int i : bigs) {
	ll w = big_val[i];
	if (i == v) {
	  ;
	} else if (ai[i] < ai[v] && ai[v] < bi[i]) {
	  int j = upper_bound(big_list[i].begin(), big_list[i].end(), ai[v])-big_list[i].begin();
	  {
	    int c = big_ind[i][j];
	    assert(ai[c] <= ai[v] && bi[c] > ai[v]);
	  }
	  w *= big_weight[i][j];
	} else {
	  w *= sz[i]*in%mod;
	}
	//cout << v << ' ' << i << ' ' << w*5%mod << " / 5" << endl;
	(ans += w) %= mod;
      }

      cout << (ans%mod+mod)%mod << '\n';
    }
  }
}