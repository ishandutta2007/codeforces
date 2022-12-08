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
typedef double ld;

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
  freopen("/Users/klimoza/CLionProjects/Test/test.in", "r", stdin);
  freopen("/Users/klimoza/CLionProjects/Test/test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int c[26];
    fill(c, c + 26, -1);
    string s; cin >> s;
    int n = s.size();
    vector<int> nxt(n, -1);
    vector<int> prv(n, -1);
    vector<int> dp(n, inf0);
    for(int i = 0; i < n; i++) {
      if(c[s[i] - 'a'] != -1) {
        prv[i] = c[s[i] - 'a'];
        nxt[c[s[i] - 'a']] = i;
      }
      c[s[i] - 'a'] = i;
    }
    for(int i = 0; i < n; i++) {
      int l = 0;
      if(i) l = dp[i - 1];
      dp[i] = min(dp[i], l + 1);
      if(nxt[i] != -1)
        dp[nxt[i]] = min(dp[nxt[i]], l + nxt[i] - i - 1);
    }
    cout << dp.back() << endl;
  }
}