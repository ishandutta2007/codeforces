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

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();
signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

const int N = 2e5 + 2;

ll dp[N][3];

ll add(ll a, ll b) {
  return (a + b) % mod;
}

ll sub(ll a, ll b) {
  return (a - b + mod) % mod;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> b(n + 1, 0);
    for(int i = 1; i <= n; i++)
      cin >> b[i];
    vector<ll> pref(n + 1, 0);
    map<ll, int> f;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    f[0] = 0;
    for(int i = 1; i <= n; i++) {
      ll prev = add(dp[i - 1][0], sub(dp[i - 1][1], dp[i - 1][2]));
      dp[i][0] = dp[i][1] = prev;
      if(f.find(pref[i - 1]) != f.end()) {
        dp[i][2] = dp[f[pref[i - 1]]][1];
      } else {
        dp[i][2] = 0;
      }
      pref[i] = pref[i - 1] + b[i];
      f[pref[i - 1]] = i;
//      cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << add(dp[n][0], sub(dp[n][1], dp[n][2])) << endl;
  }
}