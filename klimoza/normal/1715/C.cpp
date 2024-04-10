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

ll kek(vector<int> &a, int i) {
  int n = a.size();
  ll sum = 0;
  if(i > 0 && a[i] != a[i - 1]) {
    sum += i * 1ll * (n - i);
  }
  if(i < n - 1 && a[i] != a[i + 1]) {
    sum += (i + 1) * 1ll * (n - 1 - i);
  }
  return sum;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  ll sum = n * 1ll * (n + 1) / 2;
  for(int i = 0; i < n; i += 2)
    sum += kek(a, i);
  while(m--) {
    int x, i;
    cin >> i >> x; i--;
    sum -= kek(a, i);
    a[i] = x;
    sum += kek(a, i);
    cout << sum << endl;
  }
}