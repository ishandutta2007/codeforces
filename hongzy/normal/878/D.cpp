#include <bits/stdc++.h>
#define pb emplace_back
#define fs first
#define sc second
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 24;
int n, k, q, m;
bitset<4096> S[N];
vector<pii> G[N];
int main() {
  scanf("%d%d%d", &n, &k, &q);
  rep(i, 1, k) rep(j, 1, n) {
    int x; scanf("%d", &x); G[j].pb(x, i);
  }
  rep(i, 1, k) rep(j, 0, (1 << k) - 1) S[i][j] = j >> (i - 1) & 1;
  rep(i, 1, n) {
    sort(G[i].begin(), G[i].end());
    reverse(G[i].begin(), G[i].end());
  }
  m = k;
  rep(i, 1, q) {
    int op, x, y; scanf("%d%d%d", &op, &x, &y);
    if(op <= 2) S[++ m] = op == 1 ? (S[x] | S[y]) : (S[x] & S[y]);
    else {
      int c = 0;
      for(pii v : G[y]) if(S[x][c ^= 1 << (v.sc - 1)]) {
        printf("%d\n", v.fs); break ;
      }
    }
  }
  return 0;
}