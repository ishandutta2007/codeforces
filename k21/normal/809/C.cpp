#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const ll MOD = 1000000007;

int Q;
ll X1, Y1, X2, Y2, K;

ll aquery(ll times, ll pw, ll k, ll u) {
  if (times == 0 || pw == 0) {
    return 0;
  }
  if (u > k) {
    return 0;
  }
  ll lim = min(pw - 1, k - u);
  ll res = lim * (lim + 1) / 2 + (lim+1) * u;
  res %= MOD;
  res *= times;
  res %= MOD;
  /*
  DEBUG(times);
  DEBUG(pw);
  DEBUG(k);
  DEBUG(u);
  DEBUG(res);
  DEBUG("");
  */
  return res;
}

ll pquery(ll x, ll y, ll k, ll u) {
  if (x == 0 || y == 0) {
    return 0;
  }
  ll maxp = 1;
  while (maxp <= x || maxp <= y) maxp *= 2;
  maxp /= 2;
  if (x >= maxp && y >= maxp) {
    ll res = pquery(x - maxp, y - maxp, k, u);
    res += aquery(maxp, maxp, k, u);
    if (res >= MOD) res -= MOD;
    res += aquery(x - maxp, maxp, k, maxp + u);
    if (res >= MOD) res -= MOD;
    res += aquery(y - maxp, maxp, k, maxp + u);
    if (res >= MOD) res -= MOD;
    return res;
  } else if (x >= maxp) {
    ll res = pquery(x - maxp, y, k, maxp + u);
    res += aquery(y, maxp, k, u);
    if (res >= MOD) res -= MOD;
    return res;
  } else {
    ll res = pquery(x, y - maxp, k, maxp + u);
    res += aquery(x, maxp, k, u);
    if (res >= MOD) res -= MOD;
    return res;
  }
}

ll pquery(ll x, ll y, ll k) {
  return pquery(x, y, k, 1);
}

ll query(ll x1, ll y1, ll x2, ll y2, ll k) {
  ll res = pquery(x2, y2, k) - pquery(x1, y2, k) - pquery(x2, y1, k) + pquery(x1, y1, k);
  res %= MOD;
  if (res < 0) res += MOD;
  return res;
}

int main() {
  cin >> Q;
  REP(q,Q) {
    cin >> X1 >> Y1 >> X2 >> Y2 >> K;
    cout << query(X1-1, Y1-1, X2, Y2, K) << '\n';
  }
  return 0;
}