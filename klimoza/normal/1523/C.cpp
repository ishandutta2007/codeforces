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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
      cin >> i;
    vector<vector<int>> ans(n);
    vector<vector<int>> cur(n);
    cur[0] = ans[0] = {1};
    for (int i = 1; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        if (cur[j].empty()) continue;
        if (a[i] == 1) {
          cur[j + 1] = cur[j];
          cur[j + 1].push_back(1);
          ans[i] = cur[j + 1];
          break;
        }
        if (a[i] != cur[j].back() + 1)
          cur[j].clear();
        else {
          cur[j].back()++;
          ans[i] = cur[j];
          break;
        }
      }
    }
    for (auto &v : ans) {
      for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if((i + 1) < (int)(v.size()))
          cout << ".";
      }
      cout << endl;
    }
  }
}