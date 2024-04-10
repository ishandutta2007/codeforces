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
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n, m);
    vll a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vpii v(m);
    for(pii &p : v) cin >> p.x >> p.y;

    vint pos = {0};
    ll delt = 0;
    for(int i = 1; i <= n; i++) {
      delt += a[i] - b[i];
      if(delt == 0) pos.push_back(i);
    }
    if(delt != 0) { cout << "NO\n"; continue; }

    queue<pii> q;
    set<int> s;
    for(int i = 0; i <= n; i++) s.insert(i);
    vector<vint> w(n + 1);
    for(int i = 0; i < m; i++) { w[v[i].x - 1].push_back(i); w[v[i].y].push_back(i); }
    vint cnt(m, 2);
    auto upd = [&](int x) {
      s.erase(x);
      for(int y : w[x]) if(--cnt[y] == 0) q.push(v[y]);
    };
    for(int x : pos) upd(x);
    while(!q.empty()) {
      pii p = q.front();
      q.pop();
      auto it = s.lower_bound(p.x);
      while(it != s.end() && *it <= p.y) {
        auto nit = next(it);
        upd(*it);
        it = nit;
      }
    }
    cout << (s.empty() ? "YES\n" : "NO\n");
  }
}