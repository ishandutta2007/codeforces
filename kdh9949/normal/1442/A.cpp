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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    vint a(n);
    for(int &x : a) cin >> x;

    int cur = a[0];
    a[0] = 0;
    for(int i = 1; i < n; i++) {
      cur = min(cur, a[i] - a[i - 1]);
      if(cur <= 0) break;
      a[i] -= cur;
    }

    int valid = 1;
    for(int i = 0; i < n - 1; i++)
      if(a[i] > a[i + 1]) { valid = 0; cout << "NO\n"; break; }
    if(valid) cout << "YES\n";
  }

  return 0;
}