#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, u;
  cin >> n >> u;
  vector<int> e(n);
  for (int i = 0; i < n; i++)
    cin >> e[i];
  double ans = -1;
  for (int i = 0; i < n; i++) {
    int k = upper_bound(e.begin(), e.end(), e[i]+u)-e.begin()-1;
    int j = i+1;
    if (k > j) ans = max(ans, (double)(e[k]-e[j])/(e[k]-e[i]));
  }
  cout << setprecision(20) << ans << endl;
}