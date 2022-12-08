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

#define int long long

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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    ll sa = 0, sb = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sa += a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
      sb += b[i];
    }
    sort(all(a));
    sort(all(b));
    int l = -1, r = 1e7;
    while(r - l > 1) {
      int m = l + r >> 1;
      int tot = n + m;
      int del = tot / 4;
      ll s1 = sa + m * 1ll * 100;
      ll s2 = sb;
      if(del >= n) {
        s1 -= (sa + (del - n) * 1ll * 100);
      } else {
        for(int i = 0; i < del; i++)
          s1 -= a[i];
      }
      if(del > m) {
        for(int i = 0; i < (del - m); i++)
          s2 -= b[i];
      }
      if(s1 >= s2)
        r = m;
      else
        l = m;
    }
    cout << r << endl;
  }
}