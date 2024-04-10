//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
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

const double PI = acos((double)-1);
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

void solve() {
  int n; cin >> n;
  int ans = inf0;
  vector<vector<char>> f;
  for(int d = 1; d <= n; d++) {
    if(d * d > n) break;
    if((d & 1) != (n & 1)) continue;
    int left = (n - d * d) / 2;
    int add = (left + d - 1) / d;
    int md = left % d;
    int full = left / d;
    if(add + d >= ans) continue;
    ans = add + d;
    f = vector<vector<char>>(ans, vector<char>(ans, '.'));
    for(int i = 0; i < d; i++)
      for(int j = 0; j < d; j++)
        f[i][j] = 'o';
    for(int t = 0; t < full; t++) {
      for(int i = 0; i < d; i++)
        f[d + t][i] = f[i][d + t] = 'o';
    }
    for(int i = 0; i < md; i++)
      f[d + full][i] = f[i][d + full] = 'o';
  }
  if(ans == inf0)
    cout << -1 << endl;
  else {
    cout << f.size() << endl;
    for(int i = (int)f.size() - 1; i >= 0; i--) {
      for(char c : f[i])
        cout << c;
      cout << endl;
    }
  }
  return;
}