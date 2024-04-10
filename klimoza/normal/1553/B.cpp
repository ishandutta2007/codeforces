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

int rev(int i, int n) {
  return n - i - 1;
}

void solve() {
  int q; cin >> q;
  while(q--) {
    string s; cin >> s;
    string f = s;
    reverse(all(f));
    string t; cin >> t;
    int m = t.size();
    int n = s.size();
    bool fl = false;
    for(int i = 0; i < n; i++) {
      if(fl) break;
      for(int j = 0; j <= i + 1; j++) {
        if(m - j > i) continue;
        string f1 = s.substr(i - j + 1, j);
        string f2 = f.substr(rev(i - 1, n), m - j);
        if(f1 + f2 == t) {
          fl = true;
          break;
        }
      }
    }
    if(fl) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}