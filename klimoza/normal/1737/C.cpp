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

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int x, y;
    cin >> x >> y;
    int f = 0;
    int g = 0;
    set<pair<int, int>> kek;
    kek.insert(mp(x1, y1));
    kek.insert(mp(x2, y2));
    kek.insert(mp(x3, y3));
    if(kek.find(mp(1, 1)) != kek.end() && kek.find(mp(1, 2)) != kek.end() && kek.find(mp(2, 1)) != kek.end()) {
      if(x == 1 || y == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if(kek.find(mp(n, 1)) != kek.end() && kek.find(mp(n, 2)) != kek.end() && kek.find(mp(n - 1, 1)) != kek.end()) {
      if(x == n || y == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if(kek.find(mp(1, n)) != kek.end() && kek.find(mp(2, n)) != kek.end() && kek.find(mp(1, n - 1)) != kek.end()) {
      if(x == 1 || y == n)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if(kek.find(mp(n, n)) != kek.end() && kek.find(mp(n - 1, n)) != kek.end() && kek.find(mp(n, n - 1)) != kek.end()) {
      if(x == n || y == n)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (x1 == x2)
        f = x1 & 1;
      else if (x1 == x3)
        f = x1 & 1;
      else
        f = x2 & 1;
      if (y1 == y2)
        g = y1 & 1;
      else if (y1 == y3)
        g = y1 & 1;
      else
        g = y2 & 1;
      if ((x & 1) == f || (y & 1) == g)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}