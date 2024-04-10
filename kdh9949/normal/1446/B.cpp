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
#define all(v) v.begin(),v.end()

int d[2][5005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  s = " " + s;
  t = " " + t;

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      d[i & 1][j] = max(d[~i & 1][j] - 1, d[i & 1][j - 1] - 1);
      if(s[i] == t[j]) {
        d[i & 1][j] = max(d[i & 1][j], max(d[~i & 1][j - 1], 0) + 2);
      }
      ans = max(ans, d[i & 1][j]);
    }
  }

  cout << ans << '\n';
  return 0;
}