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
//const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

ll get_ans(int x, vector<int> &a) {
  int n = a.size();
  int c = 0;
  ll ans = 0;
  int lst = 0;
  for(int i = 0; i < n; i++){
    if((a[i] & 1) == x) {
      ans += abs(c - lst);
      c++;
    } else
      lst++;
  }
  return ans;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    int c[2] = {0, 0};
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      c[a[i] & 1]++;
    }
    if(abs(c[0] - c[1]) > 1)
      cout << -1 << endl;
    else {
      int ans = 0;
      if(c[0] > c[1])
       ans = get_ans(0, a);
      else if(c[0] < c[1])
        ans = get_ans(1, a);
      else
        ans = min(get_ans(0, a), get_ans(1, a));
      cout << ans << endl;
    }
  }
}