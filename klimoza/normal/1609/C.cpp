#include <math.h>
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

const int N = 1e6 + 2;
bool pr[N];

void solve() {
  fill(pr, pr + N, true);
  pr[1] = false;
  for(int i = 2; i < N; i++)
    for(ll j = i * 1ll * i; j < N; j += i)
      pr[j] = false;
  int t; cin >> t;
  while(t--) {
    int n, e; cin >> n >> e;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    vector<int> nxt(n), prv(n);
    for(int i = 0; i < n; i++) {
      if(a[i] != 1)
        prv[i] = 0;
      else if(i - e < 0)
        prv[i] = 1;
      else
        prv[i] = 1 + prv[i - e];
    }
    for(int i = n - 1; i >= 0; i--) {
      if(a[i] != 1)
        nxt[i] = 0;
      else if(i + e >= n)
        nxt[i] = 1;
      else
        nxt[i] = 1 + nxt[i + e];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      if(!pr[a[i]])
        continue;
      ll x1 = 0;
      ll x2 = 0;
      if(i - e >= 0)
        x1 = prv[i - e];
      if(i + e < n)
        x2 = nxt[i + e];
//      cout << i << " " << (x1 + 1) << " " << (x2 + 1) << endl;
      ans += (x1 + 1) * (x2 + 1) - 1;
    }
    cout << ans << endl;
  }
}