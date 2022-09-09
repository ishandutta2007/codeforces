#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

const int DEBUG = 0;
vi ord;
vvi g;

bool comp(int i, int j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  string s;
  if (!DEBUG) cin >> s;
  else {
    if (ord[i] < ord[j]) {
      s = "<";
      g[i][j] = 1;
    } else {
      s = ">";
      g[j][i] = 1;
    }
    cerr << s << endl;
  }
  return s == "<";
}

void solve() {
  int n = 4;
  if (!DEBUG) cin >> n;
  else {
    g.assign(2 * n, vi(2 * n, 0));
    ord.assign(2 * n, 0);
    for (int i = 0; i < ord.size(); ++i) ord[i] = i;
    random_shuffle(ord.begin(), ord.end());
  }
  vii p;
  vi v;
  for (int i = 0; i < 2 * n; ++i) v.push_back(i);
  while (v.size() + 2 * p.size() > n) {
    cerr << v.size() << ' ' << p.size() << endl;
    if (v.size() == 1 && 2 * p.size() == n) {
      if (comp(v.back(), p.back().second)) v.pop_back();
      else {
        v.push_back(p.back().first);
        p.pop_back();
      }
    }
    while (v.size() > 1) {
      int i = v.back();
      v.pop_back();
      int j = v.back();
      v.pop_back();
      if (!comp(i, j)) swap(i, j);
      pii x(j, i);
      for (int it = 0; it <= p.size(); ++it) if (it == p.size() || !comp(x.second, p[it].second)) {
        p.insert(p.begin() + it, x);
        break;
      }
    }
    while (p.size() * 2 - 1 >= n) {
      v.push_back(p.back().first);
      p.pop_back();
    }
  }
  cout << "!" << endl;
  if (DEBUG) {
    vi c(2 * n);
    for (int i = ord.size() - 1; i >= 0; --i) {
      for (int to = 0; to < 2 * n; ++to) if (g[ord[i]][to]) for (int x = 0; x < 2 * n; ++x) if (g[to][x]) {
        g[ord[i]][x] = 1;
      }
      for (int to = 0; to < 2 * n; ++to) if (g[ord[i]][to]) ++c[ord[i]];
      cerr << "ord c " << ord[i] + 1 << ' ' << c[ord[i]] << endl;
    }
    sort(c.begin(), c.end());
    assert(c[n] >= n);
    c.resize(n);
    vi id(n);
    for (int i = 0; i < n; ++i) id[i] = i;
    assert(c != id);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1000;
  if (!DEBUG) cin >> T;
  for (int test = 1; test <= T; ++test) {
    solve();
  }
  return 0;
}