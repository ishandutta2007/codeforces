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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vint a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 32;
  for(int i = 0; i + 1 < n; i++) {
    int lx = 0; 
    for(int j = 0; j <= ans && i - j >= 0; j++) {
      lx ^= a[i - j];
      int rx = 0;
      for(int k = 0; k <= ans && i + 1 + k < n; k++) {
        rx ^= a[i + 1 + k];
        if(lx > rx) {
          ans = min(ans, j + k);
          break;
        }
      }
    }
  }

  cout << (ans == 32 ? -1 : ans) << '\n';
  return 0;
}