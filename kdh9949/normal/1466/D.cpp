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

  ints(t);
  while(t--) {
    ints(n);
    vll a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vint deg(n + 1);
    for(int i = 0; i < n - 1; i++) {
      ints(x, y);
      deg[x]++;
      deg[y]++;
    }
    vll b;
    b.push_back(accumulate(all(a), 0LL));
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < deg[i] - 1; j++) {
        b.push_back(a[i]);
      }
    }
    sort(all(b), greater<ll>());
    partial_sum(all(b), b.begin());
    for(ll x : b) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}