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

const int N = 105, K = 10005, INF = int(1e9);
int d[2][N][K];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ints(n);
  int s = 0;
  for(int i = 0; i < 2; i++) for(int j = 0; j < N; j++) for(int k = 0; k < K; k++)
    d[i][j][k] = -INF;
  d[0][0][0] = 0;
  for(int i = 1; i <= n; i++) {
    ints(a, b);
    s += b;
    auto cd = d[i & 1], pd = d[~i & 1];
    for(int j = 0; j <= i; j++) {
      for(int k = 0; k <= 100 * n; k++) {
        cd[j][k] = pd[j][k];
        if(j >= 1 && k >= a) cd[j][k] = max(cd[j][k], pd[j - 1][k - a] + b);
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    int ans = 0;
    for(int j = 0; j <= 100 * n; j++) ans = max(ans, min(2 * j, s + d[n & 1][i][j]));
    cout << (ans / 2) << '.' << (ans % 2 * 5) << " \n"[i == n];
  }

  return 0;
}