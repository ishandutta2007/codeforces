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
  freopen("/Users/klimoza/CLionProjects/Test/test.in", "r", stdin);
  freopen("/Users/klimoza/CLionProjects/Test/test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

vector<pair<int, int>> get_ans(int n) {
  int x = (n - 2) / 3;
  vector<pair<int, int>> res;
  for(int i = 1; i <= x; i++)
    res.push_back({i, x - i + 1});
  for(int i = 1; i <= x + 1; i++)
    res.push_back({n - i + 1, n - (x + 1) + i});
  return res;
}

void solve() {
  int n; cin >> n;
  if(n == 1 || n == 2)
    cout << 1 << endl << "1 1" << endl;
  else if(n == 3)
    cout << 2 << endl << "1 2" << endl << "1 1" << endl;
  else if(n == 4)
    cout << 3 << endl << "1 1" << endl << "2 3" << endl << "3 2" << endl;
  else {
    vector<pair<int, int>> ans;
    if(n % 3 == 2) {
      ans = get_ans(n);
    } else if(n % 3 == 0) {
      ans = get_ans(n - 1);
      ans.push_back({n, n});
    } else {
      ans = get_ans(n - 2);
      ans.push_back({n - 1, n});
      ans.push_back({n, n -1});
    }
    cout << ans.size() << endl;
    for(auto u : ans)
      cout << u.first << " " << u.second << endl;
  }
}