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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    ll s= 0 ;
    int c1 = 0, c2 = 0;
    vector<ll> a(n);
    for(int i = 0; i < n ;i++) {
      cin >> a[i];
      s += a[i];
      if(a[i] & 1) {
        c1++;
      } else {
        c2++;
      }
    }
    while(q--) {
      int tp, x; cin >> tp >> x;
      if(tp == 0) {
        s += c2 * 1ll * x;
        if(x & 1) {
          c1 += c2;
          c2 = 0;
        }
      } else {
        s += c1 * 1ll * x;
        if (x & 1) {
          c2 += c1;
          c1 = 0;
        }
      }
      cout << s << endl;
    }
  }
}