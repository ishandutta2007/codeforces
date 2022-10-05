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

  int n;
  cin >> n;

  vector<set<int>> e(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].insert(y);
    e[y].insert(x);
  }

  queue<int> q;
  for(int i = 1; i <= n; i++) if(e[i].size() == 1) q.push(i);

  int ans = 0;
  vint v(n + 1);
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    
    int y = *e[x].begin();
    v[y] = y;
    for(int i : e[y]) {
      if(e[i].size() > 1) {
        e[i].erase(y);
        if(e[i].size() == 1) q.push(i);
      } else {
        v[i] = v[y];
        v[y] = i;
        e[i].clear();
        ans += 2;
      }
    }
    
    e[y].clear();
  }

  cout << ans << '\n';
  for(int i = 1; i <= n; i++) cout << v[i] << " \n"[i == n];
  return 0;
}