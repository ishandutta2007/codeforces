#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  vector<int> ma(n, h);
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = l-1; i < r; i++)
      ma[i] = min(ma[i], x);
  }
  int ans = 0;
  for (int i : ma)
    ans += i*i;
  cout << ans << endl;
}