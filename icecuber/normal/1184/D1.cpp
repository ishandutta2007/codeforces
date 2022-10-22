#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  while (t--) {
    int cmd, i;
    cin >> cmd >> i;
    if (cmd == 1) {
      if (i <= k) k++;
      n++;
    } else {
      if (i < k) {
	k -= i;
	n -= i;
      } else {
	n = i;
      }
    }
    cout << n << ' ' << k << endl;
  }
}