#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  string big, small;
  cin >> big >> small;
  vector<int> acc(max(n-m+2,1));
  for (int i = 0; i+m <= n; i++) {
    acc[i+1] = acc[i]+(big.substr(i,m)==small);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << (l < r-m+1 ? acc[r-m+1]-acc[l] : 0) << endl;
  }
}