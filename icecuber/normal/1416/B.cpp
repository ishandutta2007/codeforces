#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int&v : a) cin >> v, sum += v;
    if (sum%n) {
      cout << -1 << endl;
      continue;
    }

    vector<tuple<int,int,int>> ans;
    auto Move = [&](int i, int j, int x) {
      if (!x) return;
      assert(x >= 0);
      assert(i >= 0 && j >= 0);
      assert(i < n && j < n);
      ans.push_back({i+1, j+1, x});
      x *= i+1;
      a[i] -= x;
      a[j] += x;
    };

    int avg = sum/n;
    int k = n-1;
    while (k && a[k] < k+1) k--;
    if (k) Move(k, 0, 1);
    for (int i = 1; i <= k; i++) {
      Move(0, i, (a[i]+i)/(i+1)*(i+1)-a[i]);
      Move(i, 0, a[i]/(i+1));
    }
    vector<pair<int,int>> plan;
    for (int i = k+1; i < n; i++) {
      assert(a[i] < i+1);
      int need = i+1-a[i];
      plan.push_back({need, i});
    }
    sort(plan.begin(), plan.end());
    int ok = 1;
    for (auto [need, i] : plan) {
      if (need > a[0]) {
	ok = 0;
	break;
      }
      Move(0, i, need);
      Move(i, 0, a[i]/(i+1));
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i < n; i++) {
      Move(0, i, avg);
    }
    for (int i = 0; i < n; i++)
      assert(a[i] == avg);
    cout << ans.size() << endl;
    for (auto [i,j,x] : ans) cout << i << ' ' << j << ' ' << x << endl;
  }
}