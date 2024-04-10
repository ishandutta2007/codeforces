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

  int c[20][20] = {};
  for(int i = 0; i < n; i++) {
    if(a[i] > b[i]) {
      cout << "-1\n";
      return;
    }
    c[a[i] - 'a'][b[i] - 'a'] = 1;
  }

  int ans = 0;
  for(int i = 0; i < 20; i++) {
    int nxt = -1;
    for(int j = i + 1; j < 20; j++) {
      if(c[i][j]) {
        nxt = j;
        break;
      }
    }
    if(nxt < 0) continue;
    ans++;
    for(int j = i + 1; j < 20; j++) {
      if(c[i][j]) c[nxt][j] = 1;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--) solve();

  return 0;
}