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


ll inv(ll a) {
  ll p = mod-2;
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  assert(m == 0);

  assert(inv(12345)*12345%mod == 1);

  string s;
  cin >> s;
  vector<vl> poly;
  for (int i = 0; i < n; i++) {
    vl p;
    if (s[i] == '?') p = {1,1};
    else if ((s[i] == 'w')^(i%2)) p = {1};
    else p = {0,1};
    poly.push_back(p);
  }
  while (poly.size() > 1) {
    vector<vl> npoly;
    for (int i = 0; i < (int)poly.size(); i += 2) {
      if (i+1 == (int)poly.size())
        npoly.push_back(poly[i]);
      else
        npoly.push_back(conv(poly[i], poly[i+1]));
    }
    swap(poly, npoly);
  }

  ll exp = 0, tot = 0;
  for (int i = 0; i < (int)poly[0].size(); i++) {
    if ((i*2-n)%4) continue;
    (tot += poly[0][i]) %= mod;
    (exp += abs(i*2-n)/4 * poly[0][i]) %= mod;
  }
  cout << exp * inv(tot) % mod << endl;
}