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
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      sum += v;
    }
    cout << ((n >= k && sum) || (n < k && sum == n) ? "YES" : "NO") << endl;
  }
}