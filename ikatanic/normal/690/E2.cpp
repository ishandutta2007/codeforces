#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 605;
const int MAXK = 16;

int h, w, k;
int m[MAX][MAX];
int lower[MAX][MAX];
int upper[MAX][MAX];

llint a[MAXK][MAXK];

llint dp[MAXK][1 << MAXK];

// 16 -> 1 / 2
// 2 -> 1 / 16

void calc_dists() {
  int stripe = min(h / k, 3);
  int W = min(w, 4);

  REP(i, k) {
    REP(j, w - W + 1) {
      vector< int > u, l;
      REP(ii, stripe) {
	REP(jj, W) {
	  u.push_back(m[i * h / k + ii][j + jj]);
	  l.push_back(m[(i + 1) * h / k + ii - stripe][j + jj]);
	}
      }
      nth_element(u.begin(), u.begin() + u.size() / 2, u.end());
      nth_element(l.begin(), l.begin() + l.size() / 2, l.end());
      upper[i][j] = u[u.size() / 2];
      lower[i][j] = l[l.size() / 2];
    }
  }

  REP(i, k) REP(j, k) {
    if (i == j) continue;
    a[i][j] = 0;
    REP(r, w - W + 1) {
      a[i][j] += abs(lower[i][r] - upper[j][r]);
    }
  }
}

void solve() {
  scanf("%d%d%d", &h, &w, &k);
  REP(i, h) REP(j, w)
    scanf("%d", &m[i][j]);

  calc_dists();

  // REP(i, k) {
  //   REP(j, k)
  //     printf("%lld ", a[i][j]);
  //   puts("");
  // }

  REP(i, k) dp[i][0] = 0;

  FOR(mask, 1, 1 << k) {
    REP(i, k) {
      if (((mask >> i) & 1)) continue;
      dp[i][mask] = 1e18;
      REP(j, k) {
	if (!((mask >> j) & 1)) continue;
	dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << j)] + a[i][j]);
      }
    }
  }

  int p = 0;
  REP(i, k) if (dp[i][(1 << k) - 1 - (1 << i)] <
		dp[p][(1 << k) - 1 - (1 << p)])
    p = i;
  int m = (1 << k) - 1 - (1 << p);

  vector< int > sol = {p};

  while (m) {
    REP(i, k) {
      if (((m >> i) & 1) == 1 && 
	  dp[p][m] == dp[i][m ^ (1 << i)] + a[p][i]) {
	sol.push_back(i);
	p = i;
	m ^= (1 << i);
	break;
      }
    }
  }

  vector< int > inv(k);
  REP(i, k) inv[sol[i]] = i;

  REP(i, k)
    printf("%d ", inv[i] + 1);
  puts("");
}

int main(void) 
{
  int q;
  scanf("%d", &q);
  REP(i, q) solve();

  return 0;
}