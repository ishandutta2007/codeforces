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
  int n, x, y;
  cin >> n >> x >> y;
  y -= x;
  int u = n - x;

  vint v(n), c(n + 2, 0);
  vector<vint> p(n + 2);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    c[v[i]]++;
    p[v[i]].push_back(i);
  }

  vint iv(n + 1);
  iota(all(iv), 1);
  sort(all(iv), [&](int x, int y){
    return c[x] > c[y];
  });
  int z = iv[n];
 
  vint ans(n); 
  int ccnt = 0;
  for(int t = n; t >= 1; t--) {
    if(ccnt == x) break;
    for(int j = 0; j <= n; j++) {
      int cur = iv[j];
      if(c[cur] < t) break;
      ans[p[cur][c[cur] - 1]] = cur;
      c[cur]--;
      ccnt++;
      if(ccnt == x) break;
    }
  }

  sort(all(iv), [&](int x, int y){
    return c[x] > c[y];
  });
  ccnt = 0;
  vint cc(n + 2, 0);
  for(int t = 1; t <= n; t++) {
    if(ccnt == y) break;
    for(int j = 0; j <= n; j++) {
      int cur = iv[j];
      if(c[cur] < t) break;
      cc[cur]++;
      ccnt++;
      if(ccnt == y) break;
    }
  }

  if(*max_element(all(c)) <= u / 2) {
    vint pos, val;
    for(int i = 1; i <= n + 1; i++) {
      for(int j = 0; j < c[i]; j++) {
        pos.push_back(p[i][j]);
        val.push_back(j < cc[i] ? i : z);
      }
    }
    for(int i = 0; i < u; i++) ans[pos[i]] = val[(i + u / 2) % u];
  }
  else {
    int mx = int(max_element(all(c)) - c.begin());
    ccnt = 0;
    for(int i = 1; i <= n + 1; i++) {
      if(i == mx) continue;
      if(ccnt == y) break;
      for(int j = 0; j < c[i]; j++) {
        ans[p[mx][ccnt]] = i;
        ccnt++;
        if(ccnt == y) break;
      }
    }
    for(int i = 1; i <= n + 1; i++) {
      if(i == mx) continue;
      if(ccnt == y) break;
      for(int j = 0; j < c[i]; j++) {
        ans[p[i][j]] = mx;
        ccnt++;
        if(ccnt == y) break;
      }  
    }
    if(ccnt < y) {
      cout << "NO\n";
      return;
    }
    for(int i = 0; i < n; i++) if(!ans[i]) ans[i] = z;
  }
  
  cout << "YES\n";
  for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}