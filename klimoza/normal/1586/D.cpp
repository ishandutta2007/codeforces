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

//#define endl '\n'

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
//  freopen("test.in", "r", stdin);
//  freopen("test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

int ask(vector<int> &a) {
  cout << "? ";
  for(int i : a)
    cout << i << " ";
  cout << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  vector<int> ans(n, -1);
  for(int h = n - 1; h >= 0; h--) {
    if(ans[h] != -1) continue;
    int mn = n + 1;
    for(int j = h + 1; j < n; j++)
      mn = min(mn, ans[j]);
    vector<int> tmp(n, -1);
    tmp[h] = 0;
    vector<int> a(n, 1);
//    cout << h << " kek" << endl;
    for(int i = 1; i < n; i++) {
      a[h] = i + 1;
      int x = ask(a);
      if(x && x < h + 1)
        tmp[x - 1] = i;
      else {
        ans[h] = mn - i;
        break;
      }
    }
    if(ans[h] == -1) ans[h] = 1;
    for(int i = 0; i < n; i++) {
      if(tmp[i] != -1)
        ans[i] = tmp[i] + ans[h];
    }
  }
  cout << "! ";
  for(int i : ans)
    cout << i << " ";
  cout << endl;
}