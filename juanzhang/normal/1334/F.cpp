#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

typedef long long ll;
const int maxn = 5e5 + 10;
int n, m, A[maxn], B[maxn], C[maxn], pos[maxn];

ll dp[maxn];

struct BIT {
  ll c[maxn];
  
  void add(int pos, ll x) {
    for (; pos <= n; pos += pos & -pos) {
      c[pos] += x;
    }
  }
  
  ll query(int pos) {
    if (pos < 0) return 0;
    ll res = 0;
    for (; pos; pos &= pos - 1) {
      res += c[pos];
    }
    return res;
  }
} T1, T2;

ll val[maxn];

int main() {
  cin >> n;
  rep(i, 1, n) scanf("%d", A + i);
  rep(i, 1, n) scanf("%d", C + i);
  cin >> m;
  rep(i, 1, m) scanf("%d", B + i), pos[B[i]] = i;
  ll ans = 1e18;
  memset(val, 0x3f, sizeof val);
  val[0] = 0;
  ll sum = 0;
  rep(i, 1, n) sum += A[i] > B[m] || C[i] < 0 ? C[i] : 0;
  rep(i, 1, n) {
    T1.add(A[i], C[i]);
    T2.add(A[i], min(0, C[i]));
    sum -= A[i] > B[m] || C[i] < 0 ? C[i] : 0;
    int x = pos[A[i]];
    if (!x) continue;
    int num = B[x - 1];
    ll cur = T1.query(n) - T1.query(num) + T2.query(num);
//    printf("!!!%lld\n", cur);
    dp[i] = val[x - 1] + cur - C[i];
    if (x == m) {
      chkmin(ans, dp[i] + sum);
    } else {
      num = A[i];
      cur = T1.query(n) - T1.query(num) + T2.query(num);
      chkmin(val[x], dp[i] - cur);
    }
//    printf("#(%d %lld) ", i, dp[i]);
//    rep(j, 1, m - 1) printf("%lld ", val[j]);
//    puts("");
  }
  if (ans > 1e17) {
    puts("NO");
  } else {
    puts("YES"), cout << ans << endl;
  }
  return 0;
}