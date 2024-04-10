#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    map<ll,vector<int>> sums;
    for (int i = 0; i < n; i++) {
      ll sum = 0;
      for (int j = 0; j < m; j++) {
        ll v;
        cin >> v;
        sum += ll(j)*v;
      }
      sums[sum].push_back(i);
    }
    assert(sums.size() == 2);
    ll single = sums.begin()->first;
    ll base = sums.rbegin()->first;
    if (sums[single].size() > 1) swap(single, base);
    assert(sums[single].size() == 1);
    cout << sums[single][0]+1 << ' ' << single-base << endl;
  }
}