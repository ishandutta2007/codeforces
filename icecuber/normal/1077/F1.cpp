#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5002][5002];
ll a[6000];

#define x first
#define y second

pair<int,ll> deq[6000];
int d0, dlen;
ll query(int x) {
  while (d0 < dlen && deq[d0].x < x) d0++;
  return d0==dlen ? -1e18 : deq[d0].y;
}

void add(int x, ll v) {
  while (dlen > d0 && deq[dlen-1].y <= v) dlen--;
  deq[dlen++] = {x,v};
}

void reset() {
  d0 = dlen = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int j = 0; j < n; j++)
    dp[1][j] = j < k ? a[j] : -1e18;

  for (int i = 2; i <= x; i++) {
    reset();
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1e18;
      dp[i][j] = max(dp[i][j], query(j-k)+a[j]);
      add(j, dp[i-1][j]);
      //for (int l = max(0,j-k); l < j; l++)
      //dp[i][j] = max(dp[i][j], dp[i-1][l]+a[j]);
    }
  }
  ll ans = -1;
  for (int i = max(n-k,0); i < n; i++)
    ans = max(ans, dp[x][i]);
  cout << ans << endl;
}