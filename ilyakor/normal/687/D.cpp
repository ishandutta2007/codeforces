#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxn = 1010;

int p[maxn], Rank[maxn], col[maxn], op[maxn];

void init() {
   for (int i = 0; i < maxn; ++i) {
    p[i] = i;
  }
  memset(col, 0, sizeof(col));
  memset(op, -1, sizeof(op));
}

int root(int x) {
  if (x == p[x])
    return x;
  return p[x] = root(p[x]);
}

int unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return a;
  p[a] = b;
  return b;
  /*if (Rank[a] < Rank[b]) {
    p[a] = b;
    return b;
  } else {
    p[b] = a;
    if (Rank[a] == Rank[b])
      ++Rank[a];
    return a;
  }*/
}

bool add(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return false;
  if (col[y] == 0) {
    int t = x;
    x = y;
    y = t;
  }
  if (col[x] == 0 && col[y] == 0) {
    col[x] = 1;
    col[y] = -1;
    op[x] = y;
    op[y] = x;
    return true;
  }
  if (col[x] == 0) {
    x = unite(x, op[y]);
    col[x] = -col[y];
    op[x] = y;
    op[y] = x;
    return true;
  }
  int ox = op[x], oy = op[y];
  if (ox == y && oy == x) return true;
  x = unite(x, oy);
  y = unite(y, ox);
  col[x] = 1;
  col[y] = -1;
  op[x] = y;
  op[y] = x;
  return true;
}

int main() {
  int n, m, q;
//  n = 1000;
//  m = n * (n - 1) / 2;
//  q = 1000;
//  int ind = 0;
//  vector<pair<ii, ii>> edges;
//  for (int x = 0; x < n; ++x)
//    for (int y = 0; y < n; ++y) {
//      if (x % 2 != y % 2)
//        edges.pb(mp(ii(rand() % 1000000000, ind++), ii(x, y)));
//    }
  scanf("%d%d%d", &n, &m, &q);
  vector<pair<ii, ii>> edges;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    edges.pb(mp(ii(w, i), ii(x - 1, y - 1)));
  }
  sort(all(edges));
  for (int it = 0; it < q; ++it) {
    int l, r;
    scanf("%d%d", &l, &r);
    //l = rand() % n, r = rand() % n;
    //if (l > r) swap(l, r);
    --l, --r;
    int res = -1;
    init();
    for (int i = sz(edges) - 1; i >= 0; --i) {
      if (edges[i].first.second < l || edges[i].first.second > r) continue;
      if (add(edges[i].second.first, edges[i].second.second)) {
        
      } else {
        res = edges[i].first.first;
        break;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}