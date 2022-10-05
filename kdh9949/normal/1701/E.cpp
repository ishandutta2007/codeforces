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
int lcp[N][N], pf[N], sf[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(_);
  while(_--) {
    ints(n, m);
    strs(s, t);

    for(int i = 0; i <= n; i++) fill(lcp[i], lcp[i] + m + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
      for(int j = m - 1; j >= 0; j--) {
        lcp[i][j] = (s[i] == t[j]) * (lcp[i + 1][j + 1] + 1);
      }
    }
    for(int i = 0, j = 0; i < m; i++) {
      while(j < n && s[j] != t[i]) j++;
      pf[i] = j;
      j++;
    }
    for(int i = m - 1, j = n - 1; i >= 0; i--) {
      while(j >= 0 && s[j] != t[i]) j--;
      sf[i] = j;
      j--;
    }
    if(pf[m - 1] >= n) { cout << "-1\n"; continue; }

    int ans = n - lcp[0][0];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(s[i] != t[j]) continue;
        if(i <= (j ? pf[j - 1] : -1) || (j < m - 1 ? sf[j + 1] : n) <= i) continue;
        int cur = (n - i - lcp[i][j]) + 1 + (i + i - j);
        if(ans > cur) ans = cur;
      }
    }
    cout << ans << '\n';
  }


  return 0;
}