// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }

    vector<int> a;
    for (auto [x, y] : mp) {
      a.push_back(y);
    }

    int k = a.size();
    sort(begin(a), end(a));
    vector<int> b(k + 1);
    partial_sum(begin(a), end(a), begin(b) + 1);

    int sol = 1e9;

    for (int x=1; x<=n; x++) {
      int it = lower_bound(begin(a), end(a), x) - begin(a);
      sol = min(sol, n - x * (k - it));
    }

    cout << sol << '\n';
  }
}