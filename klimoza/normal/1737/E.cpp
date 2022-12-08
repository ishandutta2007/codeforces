#include <cmath>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

ll sub(ll a, ll b) {
  a -= b;
  if(a < 0)
    a += mod;
  return a;
}

ll add(ll a, ll b) {
  a += b;
  if(a >= mod)
    a -= mod;
  return a;
}

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll bp(ll a, ll k) {
  ll res = 1;
  while(k) {
    if(k & 1)
      res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    if(n == 1) {
      cout << 1 << endl;
      continue;
    }
    if(n == 2) {
      cout << 0 << endl << 1 << endl;
      continue;
    }

    ll go = bp(2, mod - 2);
    vector<ll> live(n);
    for(int i = 0; i < n; i++) {
      if(i == 0) {
        live[i] = 1;
      } else {
        int d = i / 2;
        if(i < n - 1)
          live[i] = mul(go, bp(bp(2, d), mod - 2));
        else
          live[i] = bp(bp(2, d), mod - 2);
      }
    }

    vector<ll> suff(n + 1, 0);

    vector<ll> ans(n, 0);
    ans[n - 1] = live[n - 1];
    suff[n - 1] = ans[n - 1];
    for(int i = n - 2; i >= 0; i--) {
      ans[i] = live[i];

      ll j = 2 * i + 1;
      if(j < n)
        ans[i] = mul(ans[i], sub(1, suff[j]));
      if(i == 0)
        ans[i] = 0;
      suff[i] = add(suff[i + 1], ans[i]);
    }
    for(int i = 0;i  < n; i++)
      cout << ans[i] << endl;
  }
}