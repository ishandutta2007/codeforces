#include <cmath>
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

vector<int> g[N];
ll s[N];

ll ans = 0;

ll dfs(int v, ll k, ll sm = 0, int p = -1) {
  ll max_path = -1;
  int cnt = 0;
  for(int u : g[v]) {
    if(u == p) continue;
    cnt++;
  }
  if(!cnt) {
    sm += s[v];
    ans += sm * k;
    return sm;
  }
  ll df = k / cnt;
  ll ost = k % cnt;
  vector<ll> kek;
  for(int u : g[v]) {
    if(u == p) continue;
    kek.push_back(dfs(u, df, sm + s[v], v));
  }
  sort(rall(kek));
  if(ost == 0) {
    return kek[0];
  } else {
    for (int i = 0; i < ost; i++)
      ans += kek[i];
    return kek[ost];
  }
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n - 1; i ++) {
      int p; cin >> p; p--;
      g[i + 1].push_back(p);
      g[p].push_back(i + 1);
    }
    for(int i =0 ; i < n; i++)
      cin >> s[i];
    dfs(0, k);
    cout << ans << endl;
    ans = 0;
    fill(s, s + n, 0);
    for(int i = 0 ;i <n; i++)
      g[i] = vector<int>();
  }
}