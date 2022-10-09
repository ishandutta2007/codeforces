// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
vector<pair<int, int>> e[200005];

int idx[200005], low[200005], dt;
int comp[200005], cnum;
bool inst[200005];
basic_string<int> st;

void scc(int x) {
  idx[x] = low[x] = ++dt;
  inst[x] = 1;
  st += x;
  for (auto [y, l] : e[x]) {
    if (idx[y] == 0) {
      scc(y);
      low[x] = min(low[x], low[y]);
    } else if (inst[y]) {
      low[x] = min(low[x], idx[y]);
    }
  }

  if (idx[x] == low[x]) {
    cnum++;
    while (1) {
      int z = st.back();
      st.pop_back();
      inst[z] = 0;
      comp[z] = cnum;
      if (z == x) {
        break;
      }
    }
  }
}

ll di[200005], gc[200005];

void dfsc(int x) {
  for (auto [y, l] : e[x]) {
    if (comp[x] == comp[y] && !di[y]) {
      di[y] = di[x] + l;
      dfsc(y);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int x, y, l;
    cin >> x >> y >> l;
    e[x].emplace_back(y, l);
  }

  for (int i=1; i<=n; i++) {
    if (!idx[i]) {
      scc(i);
    }
  }

  // resi komponente
  for (int i=1; i<=n; i++) {
    if (!di[i]) {
      di[i] = 1;
      dfsc(i);
    }
  }

  for (int i=1; i<=n; i++) {
    for (auto [j, l] : e[i]) {
      if (comp[i] == comp[j]) {
        ll p = di[i] + l;
        ll q = di[j];
        gc[comp[i]] = gcd(gc[comp[i]], abs(p-q));
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    ll v, s, t;
    cin >> v >> s >> t;
    ll g = gcd(gc[comp[v]], t);
    if (s % g == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}