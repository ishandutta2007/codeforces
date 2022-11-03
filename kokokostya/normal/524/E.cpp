

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;

const int MX = 1e5 + 17;
const int INF = 1e9;

int t[4 * MX];

void build(int v, int tl, int tr) {
 t[v] = -1;
 if (tl != tr) {
  int tm = (tl + tr) >> 1;
  build(v << 1, tl, tm);
  build((v << 1) | 1, tm + 1, tr);
 }
}

void update(int v, int tl, int tr, int pos, int val) {
 if (tl == tr)
  t[v] = val;
 else {
  int tm = (tl + tr) >> 1;
  if (pos <= tm)
   update(v << 1, tl, tm, pos, val);
  else
   update((v << 1) | 1, tm + 1, tr, pos, val);
  t[v] = min(t[v << 1], t[(v << 1) | 1]);
 }
}

int get(int v, int tl, int tr, int l, int r) {
 if (l > r)
  return INF;
 if (tl == l && r == tr)
  return t[v];
 int tm = (tl + tr) >> 1;
 return min(get(v << 1, tl, tm, l, min(r, tm)),
  get((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<int>> eh(n), ev(m);

    vector<int>X(k), Y(k);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        X[i] = x, Y[i] = y;
        eh[x].push_back(-(i + 1));
        ev[y].push_back(-(i + 1));
    }

    vector<int> chh(q, 0), chv(q, 0);

    vector<int> L(q), R(q), D(q), U(q);

    for (int i = 0; i < q; i++) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        l--, d--, r--, u--;
        eh[r].push_back(i + 1);
        ev[u].push_back(i + 1);
        L[i] = l, R[i] = r, U[i] = u, D[i] = d;
    }

    build(1, 0, m - 1);

    for (int i = 0; i < n; i++) {
        sort(eh[i].begin(), eh[i].end());
        for (int e : eh[i]) {
            if (e > 0) {
                e--;
                chh[e] = (get(1, 0, m - 1, D[e], U[e])) >= L[e];
            } else {
                e = -e;
                e--;
                update(1, 0, m - 1, Y[e], X[e]);
            }
        }
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        sort(ev[i].begin(), ev[i].end());
        for (int e : ev[i]) {
            if (e > 0) {
                e--;
                chv[e] = (get(1, 0, n - 1, L[e], R[e])) >= D[e];
            } else {
                e = -e;
                e--;
                update(1, 0, n - 1, X[e], Y[e]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ((chv[i] || chh[i]) ? "YES\n" : "NO\n");
    }

    return 0;
}