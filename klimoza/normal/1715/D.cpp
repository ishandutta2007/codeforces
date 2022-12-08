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

const int N = 1e5 + 2;
const int L = 31;
vector<pair<int, int>> g[N];

int status[N][L];

void solve() {
  for(int i = 0; i < N; i++)
    for(int j = 0; j < L; j++)
      status[i][j] = -1;
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  while(q--) {
    int i, j, x;
    cin >> i >> j >> x;
    i--; j--;
    if(i > j) swap(i, j);
    for(int l = 30; l >= 0; l--) {
      if(((1 << l) & x) == 0) {
        status[i][l] = 0;
        status[j][l] = 0;
      }
    }
    if(i == j) {
      for(int l = 0; l < L; l++)
        status[i][l] = ((1 << l) & x) >> l;
    } else {
      g[i].push_back({j, x});
    }
  }
  for(int i = 0; i < n; i++) {
    for(auto [j, x] : g[i]) {
      for(int l = 0; l < L; l++) {
        if((((1 << l) & x))) {
          if(status[i][l] == 1) continue;
          if(status[j][l] == 0) {
            status[i][l] = 1;
            continue;
          }
        } else {
          status[i][l] = status[j][l] = 0;
        }
      }
    }
    for(auto [j, x] : g[i]) {
      for(int l = 0; l < L; l++) {
        if((((1 << l) & x))) {
          if(status[i][l] == 1) continue;
          if(status[i][l] == 0) {
            status[j][l] = 1;
            continue;
          }
          if(status[j][l] == 0) {
            status[i][l] = 1;
            continue;
          }
          status[j][l] = 1;
        } else {
          status[i][l] = status[j][l] = 0;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int l = 0; l < L; l++) {
      if(status[i][l] == 1)
        a[i] += (1 << l);
    }
    cout << a[i] << " ";
  }
}