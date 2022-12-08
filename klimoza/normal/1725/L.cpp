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

int t[N];

void upd(int i, int d) {
  for(int j = i; j < N; j = j | (j + 1))
    t[j] += d;
}

int get(int i) {
  int res = 0;
  for(int j = i; j >= 0; j = (j & (j + 1)) - 1)
    res += t[j];
  return res;
}

void solve() {
  fill(t, t + N, 0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> pref(n);
  ll mini = inf;
  ll maxi = -inf;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i == 0)
      pref[i] = a[i];
    else
      pref[i] = a[i] + pref[i - 1];
    mini = min(mini, pref[i]);
    maxi = max(maxi, pref[i]);
  }
  if(mini < 0 || maxi != pref.back()) {
    cout << -1 << endl;
    return;
  }
  vector<ll> kek = pref;
  sort(all(kek));
  kek.erase(unique(all(kek)), kek.end());
  map<ll, int> f;
  for(int i = 0; i < kek.size(); i++)
    f[kek[i]] = i;
  for(int i =0; i <n; i++)
    pref[i] = f[pref[i]];
  ll mem = 0;
  for(int i = n - 1; i >= 0; i--) {
    mem += get(pref[i] - 1);
    upd(pref[i], 1);
  }
  cout << mem << endl;
}