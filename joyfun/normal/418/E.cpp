#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define fo(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
const int mn = 101000, mm = 60;
int F[mm][mn * 2], G[mm][mn], A[mn], V[mn * 2];
int n, m, len, N, tt;
map<int, int> Q;
int get(int v) {
  if (!Q.count(v)) Q[v] = ++tt, V[tt] = v;
  return Q[v];
}
int main() {
  scanf("%d", &n);
  len = min((int)(6 * sqrt(n)), n), N = (n - 1) / len + 1;
  fo(i, 0, n - 1) scanf("%d", A + i), A[i] = get(A[i]);
  fo(i, 1, N+1) {
    fo(j, 1, tt) F[i][j] = F[i - 1][j];
    fo(j, 1, n) G[i][j] = G[i - 1][j];
    fo(j, (i - 1) * len, min(i * len - 1, n - 1))++ G[i][++F[i][A[j]]];
  }
  scanf("%d", &m);
  for (; m--;) {
    int r, x, y, b;
    scanf("%d%d%d", &r, &x, &y);
    if (r == 1) {
      --y, b = y / len;
      fo(i, b + 1, N)-- G[i][F[i][A[y]]--];
      A[y] = get(x);
      fo(i, b + 1, N)++ G[i][++F[i][A[y]]];
      continue;
    }
    --y, b = y / len;
    if (x == 1) {
      printf("%d\n", V[A[y]]);
      continue;
    }
    x = (x - 2) % 2 + 2;
    int v0 = F[b][A[y]];
    fo(i, b * len, y) if (A[i] == A[y])++ v0;
    if (x == 2) {
      printf("%d\n", v0);
      continue;
    }
    int v1 = G[b][v0];
    fo(i, b * len, y) if (++F[b][A[i]] == v0)++ v1;
    printf("%d\n", v1);
    fo(i, b * len, y)-- F[b][A[i]];
  }
  return 0;
}