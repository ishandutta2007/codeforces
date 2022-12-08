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

string s[2];

int type(int i) {
  if(s[0][i] == '0' && s[1][i] == '0')
    return 0;
  if(s[0][i] == '1' && s[1][i] == '1')
    return 2;
  return 1;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    cin >> s[0] >> s[1];
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(i == (n - 1)) {
        if(!type(i))
          ans++;
        else if(type(i) == 1)
          ans += 2;
        continue;
      }
      if(type(i) == 0) {
        if(!type(i + 1)) {
          ans++;
        } else if(type(i + 1) == 1) {
          ans++;
        } else {
          ans += 2;
          i++;
        }
      } else if(type(i) == 1) {
        ans += 2;
      } else {
        if(type(i + 1) == 0) {
          ans += 2;
          i++;
        }
      }
    }
    cout << ans << endl;
  }
}