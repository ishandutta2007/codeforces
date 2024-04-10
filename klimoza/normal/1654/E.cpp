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
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 1e5 + 2;
const int K = 150;

const int MM = N * K;
const int M = 2 * N * (K + 1) + 2;

int cnt[M];
int cnt2[2 * N];
bool fl[N];

void solve() {
  fill(cnt, cnt + M, 0);
//  double f1 = clock();
  int n; cin >> n;
//  int n = 1e5;
  vector<int> a(n);
  int ans = n - 1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
//    a[i] = 1;
  }
  { // |c| <= K
    for(int c = -K; c <= K; c++) {
      for(int i = 0; i < n; i++) {
        int j = a[i] - i * 1ll * c + MM;
        cnt[j]++;
        ans = min(ans, n - cnt[j]);
      }
      for(int i = 0; i < n; i++) {
        int j = a[i] - i * 1ll * c + MM;
        cnt[j]--;
      }
    }
  }
//  cout << (clock() - f1) / CLOCKS_PER_SEC << endl;
  { // |c| >= K
    for(int i = 0; i < n; i++) {
      int h = (N + K - 1) / K;
      for(int j = i + 1; (j - i) <= h && j < n; j++) {
        if((a[j] - a[i]) % (j - i) == 0) {
          cnt2[(a[j] - a[i]) / (j - i) + N]++;
          fl[j] = 1;
        }
      }
      for(int j = i + 1; (j - i) <= h && j < n; j++) {
        if(fl[j]) {
          fl[j] = 0;
          int k = (a[j] - a[i]) / (j - i) + N;
          ans = min(ans, n - 1 - cnt2[k]);
          cnt2[k]--;
        }
      }
    }
  }
  cout << ans << endl;
//  double f2 = clock();
//  cout << (f2 - f1) / CLOCKS_PER_SEC << endl;
}