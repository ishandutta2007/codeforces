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
  int n, m, k;
  cin >> n >> m >> k;

  vector<vint> e(n + 1);
  vector<pii> elist;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
    elist.emplace_back(x, y);
    elist.emplace_back(y, x);
  }
  sort(all(elist));

  queue<int> q;
  vint deg(n + 1), chk(n + 1);
  for(int i = 1; i <= n; i++) {
    deg[i] = e[i].size();
    if(deg[i] < k) {
      chk[i] = 1;
      q.push(i);
    }
  }

  while(!q.empty()) {
    int x = q.front();
    q.pop();
    chk[x] = 2;
    if(deg[x] == k - 1) {
      vint v = {x};
      for(int i : e[x]) if(chk[i] < 2) v.push_back(i);
      if(v.size() == k) {
        int is_clique = 1;
        for(int i = 0; i < v.size(); i++) {
          for(int j = i + 1; j < v.size(); j++) {
            if(!binary_search(all(elist), pii(v[i], v[j]))) { is_clique = 0; break; }
          }
          if(!is_clique) break;
        }
        if(is_clique) {
          cout << "2\n";
          for(int i : v) cout << i << ' ';
          cout << '\n';
          return;
        }
      }
    }
    for(int i : e[x]) {
      if(chk[i]) continue;
      deg[i]--;
      if(deg[i] < k) {
        chk[i] = 1;
        q.push(i);
      }
    }
  }

  if(count(1 + all(chk), 0)) {
    vint ans;
    for(int i = 1; i <= n; i++) if(!chk[i]) ans.push_back(i);
    cout << "1 " << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
    cout << "\n";
  }
  else cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}