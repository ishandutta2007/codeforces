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
  freopen(PATH1, "r", stdin);
  freopen(PATH2, "w", stdout);
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
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  ll c1 = 0, c2 = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] % 3 == 0) {
      c1++;
    } else {
      c2++;
    }
  }
  int f1 = 0, f2 = 0;
  vector<int> col(n);
  for(int i = 0; i < n; i++) {
    if(a[i] % 3 == 0 && c1 <= c2) {
      f1++;
      col[i] = 0;
    } else if(a[i] % 3 != 0 && c2 < c1) {
      f1++;
      col[i] = 0;
    } else if(a[i] % 3 == 0 && f2 * 2 == n) {
      col[i] = 0;
      f1++;
    } else if(a[i] %3 != 0 && f2 * 2== n) {
      col[i] = 0;
      f1++;
    } else {
      col[i] = 1;
      f2++;
    }
  }
  if(c1 == 0)
    cout << 0 << endl;
  else if(c2 == 0) {
    cout << 2 << endl;
  } else if(c1 <= c2) {
    cout << 0 << endl;
  } else {
    cout << 2 << endl;
  }
  for(int i = 0; i < n; i++)
    cout << col[i];
}