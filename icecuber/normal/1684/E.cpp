#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int,int> cnt;
    for (int&v : a) cin >> v, cnt[v]++;
    int ans = cnt.size();
    int x = 0;
    multiset<int> right, take;
    int takesum = 0;
    for (auto [v,c] : cnt) right.insert(c);
    auto updateTake = [&]() {
      while (right.size() && takesum+*right.begin() <= k) {
        int v = *right.begin();
        right.erase(right.find(v));
        take.insert(v);
        takesum += v;
      }
    };
    updateTake();
    for (int m = 1; m <= n; m++) {
      int c = cnt[m-1];
      if (c) {
        if (right.count(c))
          right.erase(right.find(c));
        else {
          take.erase(take.find(c));
          takesum -= c;
          updateTake();
        }
      }
      x += !c;

      if (x > k) break;
      ans = min(ans, (int)right.size());
    }
    cout << ans << endl;
  }
}