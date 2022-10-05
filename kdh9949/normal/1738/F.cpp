#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> d(n + 1);
  for(int i = 1; i <= n; ++i) cin >> d[i];
  
  if(n == 1) { cout << "! 1" << endl; return; }

  vector<int> p(n + 1);
  const function<int(int)> f = [&](int x) { 
    return p[x] = (x == p[x] ? x : f(p[x]));
  };
  iota(p.begin(), p.end(), 0);

  vector<int> vis(n + 1);
  while(true) {
    int mx = -1, mi;
    for(int i = 1; i <= n; ++i) if(!vis[i] && mx < d[i]) { mx = d[i]; mi = i; }
    if(mx < 0) break;
    vis[mi] = 1;
    for(int i = 0; i < d[mi]; ++i) {
      cout << "? " << mi << endl;
      int x;
      cin >> x;
      if(vis[x]) {
        p[f(x)] = f(mi);
        break;
      }
      vis[x] = 1;
      p[f(x)] = f(mi);
    }
  }

  cout << "! ";
  for(int i = 1; i <= n; ++i) cout << f(i) << ' ';
  cout << endl;
}

int main() {
  //cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) { solve(); }

  return 0;
}