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
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

constexpr int N = 5005;
bool c[N][N];
int d[N], v[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n);
    vint a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      fill(c[i], c[i] + n + 1, false);
    }
    for(int i = 1; i < n; i++) {
      fill(v + 1, v + n + 1, 0);
      int mx = 0;
      for(int j = i; j <= n; j++) {
        mx = max(mx, ++v[a[j]]);
        if((j - i + 1) % 2 == 0 && 2 * mx <= (j - i + 1)) c[i][j] = 1;
      }
    }
    d[0] = 0;
    for(int i = 1; i <= n + 1; i++) {
      d[i] = -int(1e9);
      for(int j = 0; j < i; j++) {
        if((!j || i > n || a[j] == a[i]) && (j + 1 == i || c[j + 1][i - 1])) d[i] = max(d[i], d[j] + 1);
      }
    }
    cout << d[n + 1] - 1 << '\n';
  }

  return 0;
}