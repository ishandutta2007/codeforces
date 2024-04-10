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

  ints(n, m);
  vector<vint> e(n + 1), re(n + 1);
  for(int i = 0; i < m; i++) {
    ints(x, y);
    e[x].push_back(y);
    re[y].push_back(x);
  }
  constexpr int inf = int(1e9);
  vint d(n + 1, inf), ofs(n + 1);
  for(int i = 1; i < n; i++) ofs[i] = e[i].size();
  set<pii> pq;
  d[n] = 0;
  pq.emplace(0, n);
  while(!pq.empty()) {
    pii t = *pq.begin();
    pq.erase(pq.begin());
    if(t.x != d[t.y]) continue;
    for(int i : re[t.y]) if(i != n) {
      int nd = ofs[i] + t.x;
      ofs[i]--;
      if(nd < d[i]) {
        pq.erase(pii(d[i], i));
        d[i] = nd;
        pq.emplace(nd, i);
      }
    }
  }
  cout << d[1] << '\n';
}