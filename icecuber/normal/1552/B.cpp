#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int,5>> r(n);
    for (auto&a : r)
      for (int k = 0; k < 5; k++)
        cin >> a[k];

    auto cmp = [&](int a, int b) {
      int beats = 0;
      for (int k = 0; k < 5; k++)
        beats += (r[a][k] < r[b][k]);
      return beats >= 3;
    };
    int best = 0;
    for (int i = 1; i < n; i++) {
      if (!cmp(best,i)) best = i;
    }

    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (i == best) continue;
      if (!cmp(best,i)) ok = 0;
    }
    if (!ok) cout << -1 << endl;
    else cout << best+1 << endl;
  }
}