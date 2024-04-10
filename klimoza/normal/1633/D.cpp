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

const int N = 1e3 + 2;
const int K = N * 12;

int f[N];

void solve() {
  fill(f, f + N, inf0);
  f[1] = 0;
  for(int i = 2; i < N; i++) {
    for(int j = 1; j < i; j++) {
      int x = j / (i - j);
      if(x && j / x == (i - j))
        f[i] = min(f[i], f[j] + 1);
      else
        continue;
    }
  }
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    for(int i = 0; i < n ;i++) {
      cin >> b[i];
      d[i] = f[b[i]];
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
      cin >> c[i];
      s += c[i];
    }
//    for(int i = 0; i < n; i++)
//      cout << i << " " << d[i] << endl;
    if(k > n * 24)
      cout << s << endl;
    else {
      vector<vector<int>> dp(n + 1, vector<int>(k + 1, -inf0));
      dp[0][0] = 0;
      s = 0;
      for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++)
          dp[i][j] = dp[i - 1][j];
        for(int j = d[i - 1]; j <= k; j++) {
          if(dp[i - 1][j - d[i - 1]] == -inf0) continue;
          dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i - 1]] + c[i - 1]);
          s = max(s, dp[i][j]);
        }
      }
      cout << s << endl;
    }
  }
}