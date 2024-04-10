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

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int s = 0, e = n - 1, x = 0;

  vint ans;
  for(int i = n - 1; i >= 0; i--) {
    if((a[s] == b[i]) != x) ans.push_back(1);
    ans.push_back(i + 1);
    int ns = e, ne = s + (x ? -1 : 1);
    s = ns; e = ne; x ^= 1;
  }
  
  cout << ans.size() << ' ';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i + 1 == ans.size()];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}