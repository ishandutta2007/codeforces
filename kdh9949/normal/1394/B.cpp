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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vpii> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    e[x].emplace_back(z, y);
  }

  vector<vpii> cond(n + 1);
  for(int i = 1; i <= n; i++) {
    sort(all(e[i]));
    for(int j = 0; j < e[i].size(); j++) {
      int y = e[i][j].y;
      cond[y].emplace_back(e[i].size(), j);
    }
  }
  
  vpii ee[10][10];
  int chk[10][10] = {};
  for(int i = 1; i <= n; i++) {
    sort(all(cond[i]));
    for(int j = 0; j + 1 < cond[i].size(); j++) {
      if(cond[i][j] == cond[i][j + 1]) {
        pii p = cond[i][j];
        chk[p.x][p.y] = 1;
      }
    }
    cond[i].resize(int(unique(all(cond[i])) - cond[i].begin()));
    for(int j = 1; j < cond[i].size(); j++) {
      for(int k = 0; k < j; k++) {
        pii p = cond[i][j], q = cond[i][k];
        if(p.x < q.x) swap(p, q);
        ee[p.x][p.y].push_back(q);
      }
    }
  }
  for(int i = 0; i <= k; i++) for(int j = 0; j <= k; j++) {
    sort(all(ee[i][j]));
    ee[i][j].resize(int(unique(all(ee[i][j])) - ee[i][j].begin()));
  }

  function<int(int)> btk = [&](int x) {
    if(x == 0) return 1;
    int r = 0;
    for(int i = 0; i < x; i++) {
      if(chk[x][i]) continue;
      for(pii &p : ee[x][i]) chk[p.x][p.y]++;
      r += btk(x - 1);
      for(pii &p : ee[x][i]) chk[p.x][p.y]--; 
    }
    return r;
  };

  cout << btk(k) << '\n';
  return 0;
}