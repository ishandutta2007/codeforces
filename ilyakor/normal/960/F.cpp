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

const int maxn = 110 * 1000;

int n, m;

set<ii> d[maxn];

int query(set<ii>& s, int w) {
  auto it = s.lower_bound(ii(w + 1, -1));
  if (it == s.begin())
    return 0;
  --it;
  return it->second;
}

void update(set<ii>& s, int w, int val) {
  auto lit = s.lower_bound(ii(w, -1));
  if (lit != s.begin()) {
    --lit;
    if (lit->second >= val) return;
  }
  while (true) {
    auto it = s.lower_bound(ii(w, -1));
    if (it == s.end()) break;
    if (it->second <= val) {
      s.erase(it);
    } else break;
  }
  s.insert(ii(w, val));
}

int main() {
  scanf("%d%d", &n, &m);
  int res = 0;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    int best = query(d[x], w - 1);
    ++best;
    update(d[y], w, best);
    res = max(res, best);
  }
  printf("%d\n", res);
  return 0;
}