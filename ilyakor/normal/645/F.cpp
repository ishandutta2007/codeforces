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

const int maxn = 1010 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int64 pw(int64 x, int64 y) {
  int64 res = 1;
  while (y > 0) {
    if (y % 2LL == 1LL) {
      res = (res * x) % mod;
      --y;
    } else {
      x = (x * x) % mod;
      y /= 2;
    }
  }
  return res;
}

int64 f[maxn], rf[maxn];
int64 C[maxn];

int P[maxn];
vi pd[maxn];
vector<ii> pdd[maxn];
vi pr;

int k;

int d[maxn];
int64 ans[maxn];
int64 sum_ans;

void print_d() {
  for (int i = 1; i < 10; ++i) {
    cerr << d[i] << "\t";
  }
  cerr << "\n";
  for (int i = 1; i < 10; ++i)
    cerr << ans[i] << "\t";
  cerr << "\n\n";
}

void add(int x) {
  vi div;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      div.pb(i);
      if (x / i != i)
        div.pb(x / i);
    }
  }

  for (int t : div) {
    sum_ans += mod - ans[t];
    sum_ans %= mod;
  }

  for (int t : div) {
    ++d[t];
    ans[t] += ((C[d[t]] - C[d[t] - 1]) * (int64) t) % mod;
    ans[t] += mod;
    ans[t] %= mod;
  }
  for (int t : div) {
    int64 delta = C[d[t]] - C[d[t] - 1];
    if (delta == 0) continue;
    for (ii entry : pdd[t]) {
      int cur = entry.first;
      if (entry.second == 0) {
//        cerr << "inc " << cur << " " << delta << " " << t << "\n";
        ans[cur] += (delta * (int64) cur);
        //ans[cur] %= mod;
      } else {
//        cerr << "dec " << cur << " " << delta << " " << t << "\n";
        ans[cur] += mod - ((delta * (int64) cur));
        //ans[cur] %= mod;
      }
    }
  }

  for (int t : div) {
    ans[t] %= mod; ans[t] += mod;    ans[t] %= mod;
    sum_ans += ans[t];
    sum_ans %= mod;
  }
}

int main() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = (f[i - 1] * (int64) i) % mod;
    rf[i] = pw(f[i], mod - 2);
  }

  memset(P, -1, sizeof(P));
  for (int i = 2; i < maxn; ++i) {
    if (P[i] != -1) continue;
    pr.pb(i);
    P[i] = i;
    for (int j = i + i; j < maxn; j += i)
      if (P[j] == -1) P[j] = i;
  }
  for (int i = 2; i < maxn; ++i) {
    int x = i;
    while (x > 1) {
      int p = P[x];
      pd[i].pb(p);
      while (x % p == 0) x /= p;
    }
  }

  for (int i = 1; i < maxn; ++i) {
    int t = i;
    int cp = sz(pd[t]);
    for (int mask = 1; mask < (1 << cp); ++mask) {
      int cur = t;
      for (int i = 0; i < cp; ++i)
        if ((mask >> i) & 1) {
          cur /= pd[t][i];
        }
      pdd[i].pb(ii(cur, __builtin_popcount(mask) % 2));
    }
  }

  int n, q;
  scanf("%d%d%d", &n, &k, &q);

  memset(C, 0, sizeof(C));
  for (int i = k; i < maxn; ++i) {
    int64 val = f[i];
    val *= rf[k];
    val %= mod;
    val *= rf[i - k];
    val %= mod;
    C[i] = val;
//    if (i < 10) cerr << i << " " << C[i] << " " << f[i] << " " << rf[k] << " " << rf[i - k] << "\n";;
  }

  memset(d, 0, sizeof(d));
  memset(ans, 0, sizeof(ans));
  sum_ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    add(x);
//    print_d();
  }
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    add(x);
//    print_d();
    printf("%d\n", (int) sum_ans);
  }

  return 0;
}