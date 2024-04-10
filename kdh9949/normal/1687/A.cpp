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

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n);
    lls(k);
    vll a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++) { cin >> a[i]; s[i] = s[i - 1] + a[i]; }
    ll ans = 0;
    if(k <= n) {
      for(int i = 0; i + k <= n; i++) ans = max(ans, k * (k - 1) / 2 + s[i + k] - s[i]);
    }
    else {
      ans = s[n] + n * k - ll(n) * (n + 1) / 2;
    }
    cout << ans << '\n';
  }

  return 0;
}