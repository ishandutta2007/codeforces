#include <bits/stdc++.h>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();

void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> nxt(n, inf0), prv(n, inf0);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        prv[i] = 0;
      else if (i && prv[i - 1] != inf0)
        prv[i] = prv[i - 1] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1')
        nxt[i] = 0;
      else if (i < (n - 1) && nxt[i + 1] != inf0)
        nxt[i] = nxt[i + 1] + 1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (!nxt[i])
        ans[i] = 1;
      else if ((nxt[i] <= m || prv[i] <= m) && nxt[i] != prv[i])
        ans[i] = 1;
      else
        ans[i] = 0;
      cout << ans[i];
    }
    cout << endl;
  }
}