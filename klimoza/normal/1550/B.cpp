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
const ll mod = 1e9 + 9;
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
    int n, a, b;
    cin >> n >> a >> b;
    string s; cin >> s;
    int ans = a * n;
    if(b >= 0)
      ans += b * n;
    else {
      int t1 = 0, t2 = 0;
      for(int i = 0; i < n; i++) {
        if(s[i] == '1' && (!i || s[i - 1] == '0'))
          t1++;
        else if(s[i] == '0' && (!i || s[i - 1] == '1'))
          t2++;
      }
      ans += (min(t1, t2) + 1) * b;
    }
    cout << ans << endl;
  }
}