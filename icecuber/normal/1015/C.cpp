#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  vector<int> diff;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += a;
    diff.push_back(a-b);
  }
  sort(diff.rbegin(), diff.rend());
  for (int i = 0; i < n; i++) {
    if (sum <= m) {
      cout << i << endl;
      return 0;
    }
    sum -= diff[i];
  }
  if (sum <= m) cout << n << endl;
  else cout << -1 << endl;
}