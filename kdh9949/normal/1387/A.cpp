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

  int n, m;
  cin >> n >> m;

  vector<vpii> e(n + 1);
  for(int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    z *= 2;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }

  vint cpn(n + 1);
  vector<vint> clist;
  function<void(int)> cf = [&](int x) {
    cpn[x] = clist.size();
    clist.back().push_back(x);
    for(pii &i : e[x]) if(!cpn[i.x]) cf(i.x);
  };
  for(int i = 1; i <= n; i++) if(!cpn[i]) {
    clist.push_back(vint());
    cf(i); 
  }

  vint sgn(n + 1), bias(n + 1), ans(n + 1);
  function<void(int)> f = [&](int x) {
    for(pii i : e[x]) {
      if(sgn[i.x]) continue;
      sgn[i.x] = -sgn[x];
      bias[i.x] = i.y - bias[x];
      f(i.x);
    }
  };
  for(vint &v : clist) {
    int t = v[0];
    sgn[t] = 1;
    bias[t] = 0;
    f(t);

    bool det = false;
    int x;
    for(int i : v) {
      for(pii j : e[i]) {
        if(sgn[i] + sgn[j.x] == 0) {
          if(bias[i] + bias[j.x] != j.y) { cout << "NO\n"; return 0; }
        } else {
          int nx = (j.y - (bias[i] + bias[j.x])) / 2 * sgn[i];
          if(det && x != nx) { cout << "NO\n"; return 0; }
          det = true;
          x = nx;
        }
      }
    }

    if(det) {
      for(int i : v) ans[i] = sgn[i] * x + bias[i];
    } else {
      vint xs;
      for(int i : v) xs.push_back(-sgn[i] * bias[i]);
      sort(all(xs));
      int mx = xs[xs.size() / 2];
      for(int i : v) ans[i] = sgn[i] * mx + bias[i];
    }
  }

  cout << "YES\n";
  for(int i = 1; i <= n; i++) cout << (ans[i] / 2.0) << " \n"[i == n];
  return 0;
}