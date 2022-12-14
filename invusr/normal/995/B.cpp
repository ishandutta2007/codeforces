#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n * 2; i += 2) {
    int where = -1;
    for (int j = i + 1; j < n * 2; ++j) {
      if (a[j] == a[i]) {
        where = j;
        break;
      }
    }
    ans += where - i - 1;
    for (int j = where; j > i; --j) {
      a[j] = a[j - 1];
    }
  }
  cout << ans << '\n';

  return 0;
}