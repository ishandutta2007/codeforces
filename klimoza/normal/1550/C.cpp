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
      int n; cin >> n;
      vector<int> a(n);
      vector<int> prv(n, -1);
      vector<pair<int, int>> kek;
      vector<int> fun(n, -1);
      for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(!kek.empty() && kek.back().first > a[i])
          kek.pop_back();
        if(!kek.empty()) {
          prv[i] = kek.back().second;
        }
        kek.push_back(mp(a[i], i));
      }
      kek.clear();
      for(int i = 0; i < n; i++) {
        if(prv[i] == -1) continue;
        while(!kek.empty() && kek.back().first <= a[i]) {
          fun[i] = max(fun[i], kek.back().second);
          kek.pop_back();
        }
        kek.push_back(mp(a[i], prv[i]));
      }
      kek.clear();
      fill(all(prv), -1);
      for(int i = 0; i < n; i++) {
        while(!kek.empty() && kek.back().first < a[i])
          kek.pop_back();
        if(!kek.empty()) {
          prv[i] = kek.back().second;
        }
        kek.push_back(mp(a[i], i));
      }
      kek.clear();
      for(int i = 0; i < n; i++) {
        if(prv[i] == -1) continue;
        while(!kek.empty() && kek.back().first >= a[i]) {
          fun[i] = max(fun[i], kek.back().second);
          kek.pop_back();
        }
        kek.push_back(mp(a[i], prv[i]));
      }
      int l = 0, r = -1;
      ll ans = 0;
      while(l < n) {
        while(r < (n - 1) && fun[r + 1] < l) {
          r++;
        }
        ans += (r - l + 1);
//        cout << l << " " << r << endl;
        l++;
      }
      cout << ans << endl;
    }
}