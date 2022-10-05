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

void solve() {
  int n, p, k;
  cin >> n >> p >> k;

  string s;
  cin >> s;
  s = " " + s;

  int X, Y;
  cin >> X >> Y;

  vint c(n + 1);
  int ans = int(1e9);
  for(int i = n; i >= p; i--) {
    if(i + k <= n) c[i] += c[i + k];    
    c[i] += (s[i] == '0');
    ans = min(ans, c[i] * X + (i - p) * Y);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}