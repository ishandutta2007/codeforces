#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 230 there is a lso e . g . 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root) . The l as t two are > 109.
typedef vector<ll> vl;
void ntt(vl& a, vl& rt, vl& rev, int n) {
  rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
	ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
	a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
	ai += (ai + z >= mod ? z - mod : z);
      }
}

ll modpow(ll a, ll e) {
  if (e == 0) return 1;
  ll x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}

vl conv(const vl& a, const vl& b) {
  if (a.empty() || b.empty())
    return {};
  int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
  vl L(a), R(b), out(n), rt(n, 1), rev(n);
  L.resize(n), R.resize(n);
  rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
  ll curL = mod / 2, inv = modpow(n, mod - 2);
  for (int k = 2; k < n; k *= 2) {
    ll z[] = {1, modpow(root, curL /= 2)};
    rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  ntt(L, rt, rev, n); ntt(R, rt, rev, n);
  rep(i,0,n) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
  ntt(out, rt, rev, n);
  return {out.begin(), out.begin() + s};
}


vl prep(vl a) {
  int n = a.size(), k = n;
  vector<ll> dp(k+1), ndp(k+1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    ndp[0] = dp[0];
    for (int j = 1; j <= k; j++) {
      ndp[j] = (dp[j]+dp[j-1]*a[i])%mod;
    }
    swap(dp,ndp);
  }
  return dp;
}

const int nax = 1e5;
ll fac[nax], ifac[nax], inv[nax];

vl add(vl a, ll d) {
  int n = a.size();
  vl x = a, y(n,1);
  for (int i = 1; i < n; i++)
    y[i] = y[i-1]*d%mod;
  for (int i = 0; i < n; i++) {
    x[i] = x[i]*fac[n-1-i]%mod;
    y[i] = y[i]*ifac[i]%mod;
  }
  vl r = conv(x,y);
  r.resize(n);
  for (int i = 0; i < n; i++)
    r[i] = r[i]*ifac[n-1-i]%mod;
  return r;
}

struct Query {
  ll l, r, d, q;
};

int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < nax; i++) {
    inv[i] = i == 1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }

  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll&v : a) {
    cin >> v;
    v *= -1;
  }
  int q;
  cin >> q;
  vector<Query> query;

  set<int> split = {0,n};
  for (int qi = 0; qi < q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int qq, i, d;
      cin >> qq >> i >> d;
      i--;
      split.insert(i);
      split.insert(i+1);
      query.push_back({i,i+1,d+a[i],qq});
    } else {
      int qq, l, r, d;
      cin >> qq >> l >> r >> d;
      l--;
      split.insert(l);
      split.insert(r);
      query.push_back({l,r,d,qq});
    }
  }

  map<int,int> spliti;
  int c = 0;
  vector<int> splits;
  for (int s : split) {
    splits.push_back(s);
    spliti[s] = c++;
  }

  vector<vl> parts;
  for (int i = 0; i+1 < (int)splits.size(); i++) {
    vl part(a.begin()+splits[i], a.begin()+splits[i+1]);
    parts.push_back(prep(part));
  }

  for (int qi = 0; qi < q; qi++) {
    Query Q = query[qi];
    vl ans = {1};
    for (int i = 0; i+1 < (int)splits.size(); i++) {
      vl toadd;
      if (Q.l <= splits[i] && Q.r >= splits[i+1]) {
	toadd = add(parts[i], Q.q-Q.d);
      } else
	toadd = add(parts[i], Q.q);
      ans = conv(ans, toadd);
    }
    assert((int)ans.size() == n+1);
    cout << (ans[k]+mod)%mod << endl;
  }
}