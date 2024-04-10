#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

void solve() {
  int n, m;
  cin >> n >> m;

  string s;
  vector<vint> b(n + 1, vint(m + 1));
  for(int i = 1; i <= n; i++) {
    cin >> s;
    for(int j = 1; j <= m; j++) b[i][j] = (s[j - 1] == '1');
  }

  vector<vint> ans;
  auto put = [&](vint v) {
    for(int i = 0; i < 6; i += 2) b[v[i]][v[i + 1]] ^= 1;
    ans.push_back(v);
  };

  for(int i = 1; i + 1 <= n; i++) {
    for(int j = 1; j + 2 <= m; j++) {
      if(b[i][j] && b[i + 1][j]) {
        put({i, j, i + 1, j, i, j + 1});
      }
      else if(b[i][j]) {
        put({i, j, i, j + 1, i + 1, j + 1});
      }
      else if(b[i + 1][j]) {
        put({i + 1, j, i, j + 1, i + 1, j + 1});
      }
    }
  }

  for(int i = 1; i + 2 <= n; i++) {
    if(b[i][m - 1] && b[i][m]) {
      put({i, m - 1, i, m, i + 1, m});
    }
    else if(b[i][m - 1]) {
      put({i, m - 1, i + 1, m - 1, i + 1, m});
    }
    else if(b[i][m]) {
      put({i, m, i + 1, m - 1, i + 1, m});
    }
  }

  vector<pii> v = {{n - 1, m - 1}, {n, m - 1}, {n - 1, m}, {n, m}};
  while(true) {
    int cnt = b[n - 1][m - 1] + b[n - 1][m] + b[n][m - 1] + b[n][m];
    if(!cnt) break;
    if(cnt == 1) {
      if(b[n][m]) put({n, m, n - 1, m, n, m - 1});
      else put({n - 1, m - 1, n - 1, m, n, m - 1});
    }
    else if(cnt == 2) {
      vector<int> w;
      for(pii &p : v) if(!b[p.x][p.y]) { w.push_back(p.x); w.push_back(p.y); }
      for(pii &p : v) if(b[p.x][p.y]) { w.push_back(p.x); w.push_back(p.y); break; }
      put(w);
    }
    else if(cnt == 3) {
      vector<int> w;
      for(pii &p : v) if(b[p.x][p.y]) { w.push_back(p.x); w.push_back(p.y); }
      put(w);
    }
    else put({n, m, n - 1, m, n, m - 1});
  }

  cout << ans.size() << '\n';
  for(auto &i : ans) {
    for(int &j : i) cout << j << ' ';
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}