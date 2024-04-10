#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll root = 62;
typedef vector<ll> poly;

ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

void ntt(ll*in, ll*out, ll*cache, int n, int s) {
  if (n == 1) {
    out[0] = in[0];
    return;
  }
  int n2 = n/2;
  ntt(in, out, cache, n2, s*2);
  ntt(in+s, out+n2, cache, n2, s*2);
  for (int i = 0; i < n/2; i++) {
    ll a = out[i], b = cache[s*i]*out[i+n2] % mod;
    out[i] = a+b >= mod ? a+b-mod : a+b;
    out[i+n2] = a-b < 0 ? a-b+mod : a-b;
  }
}

poly ntt(poly a, int n, int dir = 1) {
  a.resize(n);
  if (n <= 1) return a;
  poly a_(n), cache(n);
  cache[0] = 1;
  int pw = (mod-1)/n;
  assert(abs(dir) == 1);
  if (dir == -1) pw = mod-1-pw;
  cache[1] = bin_pow(root, pw);
  for (int i = 2; i < n; i++) {
    cache[i] = cache[i-1]*cache[1]%mod;
  }
  for (int i = 0; i < n; i++)
    a[i] = (a[i]%mod+mod)%mod;
  ntt(&a[0],&a_[0],&cache[0],n,1);
  return a_;
}

poly operator*(poly a, poly b) {
  int rsz = a.size()+b.size()-1, n = 1;
  while (n < rsz) n *= 2;
  a = ntt(a, n, 1);
  b = ntt(b, n, 1);
  ll in = bin_pow(n, mod-2);
  for (int i = 0; i < n; i++) {
    a[i] = a[i]*b[i]%mod*in%mod;
  }
  a = ntt(a, n,-1);
  a.resize(rsz);
  return a;
}

poly pow(poly a, int p) {
  int rsz = a.size()*p-p+1, n = 1;
  while (n < rsz) n *= 2;
  a = ntt(a,n,1);
  ll in = bin_pow(n, mod-2);
  for (int i = 0; i < n; i++) {
    a[i] = bin_pow(a[i], p);
    a[i] = a[i]*in%mod;
  }
  a = ntt(a, n, -1);
  a.resize(rsz);
  return a;
}

int main() {
  assert(mod == (119<<23)+1);

  if (0){
    poly r = pow({1,2},100);
    for (ll v : r) cout << (v+mod)%mod << ' ';
    cout << endl;
    return 0;
    }
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ++m[a];
  }
  vector<int> b(k);
  for (int&v : b) cin >> v;

  poly A = {1,2};
  poly B = {1,2,1};
  vector<poly> ans;
  for (int ki = 0; ki < k; ki++) {
    int ca = 0, cb = 0;
    for (auto p : m) {
      if (p.first >= b[ki]) break;
      if (p.second == 1) ca++;
      else cb++;
    }
    ans.push_back(pow(A, ca)*pow(B, cb));
  }
  int q;
  cin >> q;
  while (q--) {
    int per;
    cin >> per;
    ll sum = 0;
    for (int ki = 0; ki < k; ki++) {
      int i = per/2-b[ki]-1;
      if (i >= 0 && i < ans[ki].size())
	sum += ans[ki][i];
    }
    cout << (sum%mod+mod)%mod << '\n';
  }
}