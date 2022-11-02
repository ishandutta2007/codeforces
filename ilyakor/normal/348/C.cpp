
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
#include <bitset>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int64 mod = 2184057LL;

const int maxn = 105 * 1000;

const int BUBEN = 350;

vi g[maxn];
bool bad[maxn];
bitset<maxn>* b[maxn];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int64> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  vi baddies;
  vector<int64> bb(n, 0);
  vector<int64> bbb(n, 0);
  vector<int64> ss(n, 0);
  for (int i = 0; i < m; ++i) {
    int cnt;
    scanf("%d", &cnt);
    ss[i] = cnt;
    if (cnt >= BUBEN) {
      bad[i] = true;
      baddies.pb(i);
      b[i] = new bitset<maxn>();
      for (int j = 0; j < cnt; ++j) {
        int x;
        scanf("%d", &x);
        --x;
        (*(b[i]))[x] = true;
        bbb[i] += a[x];
      }
    } else {
      bad[i] = false;
      for (int j = 0; j < cnt; ++j) {
        int x;
        scanf("%d", &x);
        --x;
        g[i].pb(x);
      }
    }
  }
  int** d = new int*[m];
  for (int i = 0; i < m; ++i) {
    d[i] = new int[baddies.size()];
    for (int j = 0; j < baddies.size(); ++j)
      d[i][j] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (bad[i]) {
      for (int j = 0; j < baddies.size(); ++j)
        d[i][j] = ((*(b[i])) & (*(b[baddies[j]]))).count();
    } else {
      for (int j = 0; j < sz(g[i]); ++j) {
        int x = g[i][j];
        for (int t = 0; t < baddies.size(); ++t)
          if (b[baddies[t]]->operator[](x)) {
            d[i][t] += 1;
          }
      }
    }
  }

  for (int i =0 ; i < q; ++i) {
    char c[5];
    scanf("%s", c);
    if (c[0] == '?') {
      int k;
      scanf("%d", &k);
      --k;
      int64 res = 0;
      if (!bad[k]) {
        for (int j = 0; j < sz(g[k]); ++j)
          res += a[g[k][j]];
        for (int j = 0; j < sz(baddies); ++j)
          res += bb[baddies[j]] * (int64)(d[k][j]);
      } else {
        res = bbb[k];
      }
      printf("%I64d\n", res);
    } else {
      int k, x;
      scanf("%d%d", &k, &x);
      --k;
      if (!bad[k]) {
        for (int j = 0; j < sz(g[k]); ++j)
          a[g[k][j]] += x;
      } else {
        bb[k] += x;
      }
      for (int j = 0; j < sz(baddies); ++j)
         bbb[baddies[j]] += x * (int64)(d[k][j]);
    }
  }
  return 0;
}