#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int sum = 0;
  for (int&v : a) cin >> v, sum += v;
  for (int i = 0; i < q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      x--;
      sum -= a[x];
      a[x] ^= 1;
      sum += a[x];
    } else {
      cout << (x <= sum) << endl;
    }
  }
}