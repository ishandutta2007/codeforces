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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const static ll M = ll(1e9) + 7;

  ints(t);
  while(t--) {
    ints(n);
    vll a(n);
    for(ll &x : a) cin >> x;
    
    vll cnt(61);
    for(int i = 0; i <= 60; i++) {
      for(int j = 0; j < n; j++) {
        if((a[j] >> i) & 1) cnt[i]++;
      }
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      ll as = 0, os = 0, t = 1;
      for(int j = 0; j <= 60; j++, t = 2 * t % M) {
        if((a[i] >> j) & 1) {
          as = (as + cnt[j] * t) % M;
          os = (os + n * t) % M;
        }
        else {
          os = (os + cnt[j] * t) % M;
        }
      }
      ans = (ans + as * os) % M;
    }
    writeln(ans);
  }

  return 0;
}