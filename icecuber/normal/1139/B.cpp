#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&i : a) cin >> i;
  ll ans = 0;
  int ma = 1e9+1;
  for (int i = n-1; i >= 0; i--) {
    int buy = min(ma, a[i]);
    ans += buy;
    ma = max(0, min(ma, buy-1));
  }
  cout << ans << endl;
}