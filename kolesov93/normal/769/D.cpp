#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 100111;
int ones[N];
int cnt[N];


int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ++cnt[x];
    mx = max(mx, x);
  }
  for (int i = 1; i < N; ++i) {
    ones[i] = ones[i & (i - 1)] + 1;
  }

  ll ans = 0;
  if (k == 0) {
    for (int i = 0; i <= mx; ++i) {
      ans += ll(cnt[i]) * (cnt[i] - 1) / 2;
    }
  } else {
    for (int i = 0; i <= mx; ++i) {
      for (int j = 0; j < i; ++j) {
        if (ones[i ^ j] == k) {
          ans += ll(cnt[i]) * cnt[j];
        }
      }
    }
  }

  cout << ans << endl;


  return 0;
}