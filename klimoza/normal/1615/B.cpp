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

const int N = 2e5 + 2;
const int L = 30;
int cnt[N][L];

void solve() {
   int t; cin >> t;
   for(int i = 0; i < L; i++)
     cnt[0][i] = 0;
   for(int i = 1; i < N; i++) {
     for(int j = 0; j < L; j++) {
       cnt[i][j] = cnt[i - 1][j];
       if((1 << j) & i)
         cnt[i][j]++;
     }
   }
   while(t--) {
     int l, r; cin >> l >> r;
     int ans = r - l + 1;
     for(int i = 0; i < L; i++)
       ans = min(ans, (r - l + 1) - (cnt[r][i] - cnt[l - 1][i]));
     cout << ans << endl;
   }
}