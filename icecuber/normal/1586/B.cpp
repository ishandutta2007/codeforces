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
    set<int> bad;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      bad.insert(b);
    }
    int mid = 1;
    while (bad.count(mid)) mid++;
    for (int i = 1; i <= n; i++) {
      if (i == mid) continue;
      cout << i << ' ' << mid << endl;
    }
  }
}