// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, q;
int a[300005];
basic_string<int> e[300005];

int br(int x, int l, int r) {
  auto it1 = lower_bound(begin(e[x]), end(e[x]), l);
  auto it2 = lower_bound(begin(e[x]), end(e[x]), r+1);
  return it2 - it1;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> q;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    e[a[i]] += i;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    vector<int> s(30);
    for (int i=0; i<30; i++) {
      s[i] = a[uniform_int_distribution<int>(l, r)(eng)];
    }
    sort(begin(s), end(s));
    s.erase(unique(begin(s), end(s)), end(s));

    int ans = 1;
    for (int x : s) {
      int t = br(x, l, r);
      if (2*t > r-l+1) {
        ans = 2*t - (r-l+1);
        break;
      }
    }

    cout << ans << "\n";
  }
}