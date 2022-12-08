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

int askOR(int i, int j) {
  cout << "or " << i + 1 << " " << j + 1 << endl;
  int x; cin >> x;
  return x;
}

int askAND(int i, int j) {
  cout << "and " << i + 1 << " " << j + 1 << endl;
  int x; cin >> x;
  return x;
}

void ans(int x) {
  cout << "finish " << x << endl;
}

void solve() {
  int n, k; cin >> n >> k;
  int t1 = askOR(0, 1);
  int t2 = askOR(1, 2);
  int f1 = askAND(0, 1);
  int f2 = askAND(0, 2);
  int x = 0;
  for(int i = 0; i < 30; i++) {
    if((t1 & (1 << i)) && (t2 & (1 << i))) {
      if(!(f2 & (1 << i)))
        x |= (1 << i);
      else if(f1 & (1 << i))
        x |= (1 << i);
    }
  }
  vector<int> a(n);
  a[1] = x;
  for(int i = 0; i < 30; i++) {
    if(t1 & (1 << i)) {
      if(!(x & (1 << i)))
        a[0] |= (1 << i);
      else if(f1 & (1 << i))
        a[0] |= (1 << i);
    }
  }
  for(int i = 2; i < n; i++) {
    int y1 = askAND(1, i);
    int y2 = askOR(1, i);
    for(int j = 0; j < 30; j++) {
      if(y2 & (1 << j)) {
        if(!(x & (1 << j)))
          a[i] |= (1 << j);
        else if(y1 & (1 << j))
          a[i] |= (1 << j);
      }
    }
  }
  sort(all(a));
  ans(a[k - 1]);
}