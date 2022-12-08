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

int n;
const int N = 4e3 + 2;
bool g[N][N];
int col[N];

bool nice_vertex[N];
bool is_cutpoint[N];

bool used[N];
int timer, tin[N], fup[N];

void dfs_col (int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  int children = 0;
  for (int u = 0; u < n; u++) {
    if (!g[v][u]) continue;
    int to = u;
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs_col(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] >= tin[v] && p != -1)
        is_cutpoint[v] = true;
      ++children;
    }
  }
  if (p == -1 && children > 1)
    is_cutpoint[v] = true;
}

void dfs(int v, int cur_col, int p = -1) {
  col[v] = cur_col;
  int s = 0;
  for(int u = 0; u < n; u++) {
    if(!g[v][u]) continue;
    s++;
    if(col[u] == -1)
      dfs(u,  cur_col, v);
  }
  if(s <= 1)
    nice_vertex[v] = true;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    cin >> n;
    fill(col, col + n, -1);
    fill(nice_vertex, nice_vertex + n, false);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        char c; cin >> c;
        if(c == '1')
          g[i][j] = true;
        else
          g[i][j] = false;
      }
    }

    int m = 0;
    for(int i = 0; i < n; i++) {
      if(col[i] == -1) {
        dfs(i, m);
        m++;
      }
    }

    fill(is_cutpoint, is_cutpoint + n, false);
    fill(used, used + n, false);
    timer = 0;
    for(int i = 0; i < n; i++) {
      if(!used[i])
        dfs_col(i);
    }

    if(m == 1) {
      cout << 0 << endl;
      continue;
    }

    vector<vector<int>> comp(m, vector<int>());
    for(int i = 0; i < n; i++)
      comp[col[i]].push_back(i);

    bool fl = false;
    for(int i = 0; i < m; i++) {
      int v = -1;
      int sz = (int)comp[i].size();
      for(int j = 0; j < sz; j++) {
        for(int k = j + 1; k < sz; k++) {
          if(!g[comp[i][j]][comp[i][k]]) {
            if(nice_vertex[comp[i][j]] || !is_cutpoint[comp[i][j]]) {
              v = comp[i][j];
              break;
            }
            if(nice_vertex[comp[i][k]] || !is_cutpoint[comp[i][k]]) {
              v = comp[i][k];
              break;
            }
          }
        }
        if(v != -1)
          break;
      }
      if(v != -1) {
        cout << 1 << endl << v + 1 << endl;
        fl = true;
        break;
      }
    }

    if(fl) {
      continue;
    }

    int mini = 0;
    for(int i = 1; i < m; i++) {
      if(comp[i].size() < comp[mini].size()) {
        mini = i;
      }
    }

    if(comp[mini].size() == 1) {
      cout << 1 << endl << comp[mini][0] + 1 << endl;
      continue;
    }

    if(m > 2) {
      cout << 2 << endl << comp[0][0] + 1 << " " << comp[1][0] + 1 << endl;
      continue;
    }

    cout << comp[mini].size() << endl;
    for(int i : comp[mini])
      cout << i + 1 << " ";
    cout << endl;
  }
}