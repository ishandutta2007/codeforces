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

void solve() {
  int t; cin >> t;
  while(t--) {
    string s;
    string t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    bool fl = false;
    int parity = (n ^ m) & 1;
    for(int tmp = 0; tmp < 2; tmp++) {
      if(parity == tmp) continue;
      int ans[2] = {0, 0};
      for (int i = 0; i < n; i++) {
        int j = (i & 1) ^ 1;
        if(ans[i & 1] == 0 && ans[j] == 0) {
          if(tmp == 0 && (i & 1) == 0) continue;
          if(tmp == 1 && (i & 1) == 1) continue;
        }
        if (s[i] == t[ans[j]]) {
          ans[i & 1] = max(ans[i & 1], ans[j] + 1);
        }
        if (ans[i & 1] == m) break;
      }
      if(max(ans[0], ans[1]) == m)
        fl = true;
    }
    if(fl)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}