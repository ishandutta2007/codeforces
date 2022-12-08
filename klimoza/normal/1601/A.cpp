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

const int L = 30;
int cnt[L];

int gcd(int a, int b) {
  while(b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    fill(cnt, cnt + L, 0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      for(int j = 0; j < L; j++) {
        if((1 << j) & a[i])
          cnt[j]++;
      }
    }
    int g = 0;
    for(int i = 0; i < L; i++) {
      if(!cnt[i]) continue;
      if(g == 0) g = cnt[i];
      else g = gcd(g, cnt[i]);
    }
    vector<int> a1, a2;
    for(int i = 1; i * 1ll * i <= g; i++) {
      if(g % i == 0) {
        a1.push_back(i);
        if(i * 1ll * i != g)
          a2.push_back(g/i);
      }
    }
    if(g == 0) {
      for(int i = 1; i <= n; i++)
        cout << i << " ";
    } else {
      reverse(all(a2));
      for (int i : a1)
        cout << i << " ";
      for (int i : a2)
        cout << i << " ";
    }
    cout << endl;
  }
}