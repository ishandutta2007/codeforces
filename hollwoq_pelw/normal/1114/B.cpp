#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1000500;
const int MOD = 1000000007;

void bad() {
  cout << "No" << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), greater<pair<int,int>>());
  long long res = 0;
  vector<int> result;
  for (int i = 0; i < m * k; ++i) {
    res += a[i].first;
    result.push_back(a[i].second);
  }
  sort(result.begin(), result.end());

  cout << res << endl;
  for (int i = 0; i < k - 1; ++i) {
    cout << result[(i + 1) * m - 1] + 1 << ' ';
  }
  return 0;
}