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

ll gcd(ll a, ll b) {
  while(b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) {
  if(!a) return b;
  return a * b / gcd(a, b);
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p(n);
    for(int i =0 ; i < n; i++) {
      cin >> p[i]; p[i] --;
    }
    vector<bool> used(n, false);
    ll l = 0;
    for(int i = 0; i < n; i++) {
      if(used[i]) continue;
      int x = p[i];
      used[x] = true;
      string g = "";
      g += s[i];
      while(x != i) {
        used[x] = true;
        g += s[x];
        x = p[x];
      }
      for(int j = 1; j <= g.size(); j++) {
        bool fl = true;
        for(int k = 0; k < g.size(); k++) {
          if(g[k] != g[(j + k) % g.size()]) {
            fl = false;
            break;
          }
        }
        if(fl) {
          l = lcm(l, j);
          break;
        }
      }
//      cout << i << " " << l << " " << g << endl;
    }
    cout << l << endl;
  }
}