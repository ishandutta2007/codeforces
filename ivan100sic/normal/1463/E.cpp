// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k, c, oo;
int p[300005], f[300005], g[300005], r[300005], o[300005], b[300005];

basic_string<int> e[300005];
int sol[300005], len, oi[300005];
int soli[300005];

void dfs(int x) {
  o[x] = -1;
  for (int y : e[x]) {
    if (!o[y]) {
      dfs(y);
    }
  }
  o[x] = ++oo;
  oi[oo] = x;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> k;
  for (int i=1; i<=n; i++) {
    cin >> p[i];
  }

  for (int i=0; i<k; i++) {
    int x, y;
    cin >> x >> y;
    f[x] = y;
    g[y] = x;
  }

  for (int i=1; i<=n; i++) {
    if (g[i] == 0) {
      int t = i;
      c++;
      b[c] = i;
      while (t) {
        r[t] = c;
        t = f[t];
      }
    }
  }

  for (int i=1; i<=n; i++) {
    if (!r[i]) {
      cout << "0\n";
      return 0;
    }
  }

  for (int i=1; i<=n; i++) {
    if (p[i]) {
      int j = p[i]; // j -> i (rev)
      e[r[i]] += r[j];
    }
  }

  for (int i=1; i<=c; i++) {
    if (!o[i]) {
      dfs(i);
    }
  }

  for (int i=1; i<=c; i++) {
    int x = oi[i];
    int t = b[x];
    while (t) {
      sol[++len] = t;
      t = f[t];
    }
  }

  // moze
  for (int i=1; i<=n; i++) {
    soli[sol[i]] = i;
  }

  bool ok = 1;

  for (int i=1; i<=n; i++) {
    if (p[i]) {
      ok &= soli[p[i]] < soli[i];
    }
  }

  // cerr << "ok1 " << ok << "\n";

  for (int i=1; i<=n; i++) {
    if (f[i]) {
      if (soli[i] + 1 != soli[f[i]]) {
        ok = 0;
      }
    }
  }

  // cerr << "ok2 " << ok << "\n";

  if (!ok) {
    cout << "0\n";
    return 0;
  }

  for (int i=1; i<=n; i++) {
    cout << sol[i] << " \n"[i == n];
  }
}