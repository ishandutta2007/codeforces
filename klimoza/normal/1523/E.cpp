#include <bits/stdc++.h>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();

void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

const int N = 1e5 + 2;

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
}

ll bp(ll a, ll k) {
  ll res = 1;
  while (k) {
    if (k & 1)
      res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}

ll fac[N], rev[N];

void build() {
  fac[0] = 1;
  for(int i = 1; i < N; i++)
    fac[i] = mul(fac[i - 1], i);
  rev[N - 1] = bp(fac[N - 1], mod - 2);
  for(int i = N - 2; i >= 0; i--) {
    rev[i] = mul(rev[i + 1], i + 1);
  }
}

ll C(ll n, ll k) {
  if(n < k || k <= 0 || n <= 0)
    return 0;
  return mul(fac[n], mul(rev[k], rev[n - k]));
}

void solve() {
  build();
  int t; cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    k--;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
      if((i - 1) * (k + 1) + 1 > n)
        break;
      ll al = mul(C(n - (i - 1) * k, i), (n - i));
      ll good = mul(C(n - i * k, i + 1), (i + 1));
      ll alll = mul(C(n, i + 1), (i + 1));
      ll prob = mul((al - good + mod) % mod, bp(alll, mod - 2));
      ans = add(ans, mul(i + 1, prob));
    }
    cout << ans << endl;
  }
}