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
//const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      char c; cin >> c;
      if(c == '-')
        a[i] = -1;
      else
        a[i] = 1;
    }
    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] + (i & 1 ? -1 : 1) * a[i];
    }
    while(q--) {
      int l, r; cin >> l >> r; l--; r--;
      int ans = pref[r];
      if(l) ans -= pref[l - 1];
      if(!ans)
        cout << 0 << endl;
      else if(ans & 1)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}