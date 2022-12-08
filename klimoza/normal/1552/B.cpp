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

bool good(vector<int> &r1, vector<int> &r2) {
  int c = 0;
  for(int i = 0; i < 5; i++)
    if(r1[i] < r2[i])
      c++;
  return c >= 3;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<vector<int>> r(n, vector<int>(5, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < 5; j++)
        cin >> r[i][j];
    int cur = 0;
    while(true) {
      bool fl = true;
      for(int i = cur + 1; i < n; i++) {
        if(!good(r[cur], r[i])) {
          fl = false;
          cur = i;
          break;
        }
      }
      if(fl) break;
    }
    bool fl = true;
    for(int i = 0; i < n; i++) {
      if(i == cur) continue;
      if(!good(r[cur], r[i])) {
        fl = false;
        break;
      }
    }
    if(fl) cout << cur + 1 << endl;
    else cout << -1 << endl;
  }
}