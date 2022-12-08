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

const int N = 11;
int a[N];

bool rec(int n, int j, ll s = 0, int i = 0) {
  if(i == n)
    return s == a[j];
  if(i == j)
    return rec(n, j, s, i + 1);
  return rec(n, j, s - a[i], i + 1) || rec(n, j, s, i + 1) || rec(n, j, s + a[i], i + 1);
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i];
    bool fl = false;
    for(int i = 0; i < n; i++)
      if(rec(n, i))
        fl = true;
    if(fl) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}