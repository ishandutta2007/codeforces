#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int N = 512, M = 998244353;
int a[N][N + 1];
int inv(int x) {
  int r = 1;
  for(int k = M - 2; k; k /= 2, x = ll(x) * x % M)
    if(k & 1) r = ll(r) * x % M;
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ints(n, m);
  vector<vint> e(n + 1);
  for(int i = 0; i < m; i++) {
    ints(x, y);
    e[x].push_back(y);
  }

  vint g(n + 1, -1);
  function<int(int)> f = [&](int x) {
    if(g[x] >= 0) return g[x];
    vint v;
    for(int i : e[x]) v.push_back(f(i));
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    v.push_back(int(1e9));
    for(int i = 0; i < v.size(); i++) if(i != v[i]) return g[x] = i;
    assert(0); // should not reach here
  };
  for(int i = 1; i <= n; i++) f(i);

  for(int i = 0; i < N; i++) {
    if(i > 0) a[i][N] = 1;
    a[i][i] = n + 1;
    for(int j = 1; j <= n; j++) a[i][i ^ g[j]]--;
    for(int j = 0; j < N; j++) (a[i][j] += M) %= M;
  }

  // solve
  for(int i = 0; i < N; i++) {
    if(a[i][i] == 0) {
      for(int j = i + 1; j < N; j++) if(a[j][i] != 0) {
        for(int k = i; k <= N; k++) swap(a[j][k], a[i][k]);
        break;
      }
      assert(0); // should not reach here
    }
    for(int j = i + 1; j < N; j++) if(a[j][i] != 0) {
      ll coeff = ll(a[j][i]) * inv(a[i][i]) % M;
      for(int k = i; k <= N; k++) if(a[i][k]) {
        a[j][k] = (a[j][k] - coeff * a[i][k] % M + M) % M;
      }
    }
  }

  for(int i = N - 1; i >= 0; i--) {
    a[i][N] = ll(a[i][N]) * inv(a[i][i]) % M;
    a[i][i] = 1;
    for(int j = 0; j < i; j++) if(a[j][i]) {
      a[j][N] = (a[j][N] - ll(a[i][N]) * a[j][i] % M + M) % M;
      a[j][i] = 0;
    }
  }
  
  writeln(a[0][N]);
  return 0;
}