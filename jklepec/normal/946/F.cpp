#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 105, mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}

int n;
string s;

int bit[MAXN];
int dp[MAXN][MAXN][MAXN];

int calc(int l, int r, int x) {
  if(dp[l][r][x] != -1) return dp[l][r][x];

  if(x < 2) {
    if(l != r - 1)
      return 0;
    if(s[l] - '0' != x)
      return 0;
    return 1;
  }

  int ret = 0;

  FOR(k, l + 1, r) {
    ret = add(ret, mul(calc(l, k, x - 1), calc(k, r, x - 2)));
  }
  int factor = 1;
  if(r == n) {
    factor = bit[x - 2];
  }
  ret = add(ret, mul(calc(l, r, x - 1), factor));

  factor = 1;
  if(l == 0) {
    factor = bit[x - 1];
  }
  ret = add(ret, mul(calc(l, r, x - 2), factor));

  return dp[l][r][x] = ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  bit[0] = bit[1] = 2;
  FOR(i, 2, MAXN) {
    bit[i] = mul(bit[i - 1], bit[i - 2]);
  }

  memset(dp, -1, sizeof dp);

  int x; cin >> n >> x >> s;

  cout << calc(0, n, x);
}