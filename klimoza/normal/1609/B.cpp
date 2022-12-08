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

bool check(int i, vector<char> &a) {
  int n = a.size();
  if(i < 0)
    return false;
  if(i + 1 >= n || i >= n || i + 2 >= n)
    return false;
  if(a[i] != 'a' || a[i + 1] != 'b' || a[i + 2] != 'c')
    return false;
  return true;
}

void solve() {
  int n; cin >> n;
  int q; cin >> q;
  vector<char> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> p(n);
  for(int i = 0; i < n; i++)
    p[i] = check(i, a);
  int s = 0;
  for(int i = 0; i < n; i++)
    s += p[i];
  while(q--) {
    int i; char c;
    cin >> i >> c; i--;
    int was = check(i - 2, a) + check(i - 1, a) + check(i, a);
    a[i] = c;
    int nw = check(i - 2, a) + check(i - 1, a) + check(i, a);
    s += nw - was;
    cout << s << endl;
  }
}