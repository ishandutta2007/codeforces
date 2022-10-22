#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //for (int n = 1; n <= 10; n++) {
  //  for (int k = 1; k <= n; k++) {
  int n, k;
  cin >> n >> k;
  if (n%2 && k%2 == 0) {
    cout << -1 << endl;
    return 0;
  }

  int x = 0;
  while (k*x < n || (k*x-n)%2 || ((k*x-n)/2+n-1)/n*2+1 > x) x++;

  vector<int> left(n);
  int extra = (k*x-n)/2, base = extra/n*2;
  for (int i = 0; i < n; i++) {
    left[i] = 1+base+(i<extra%n)*2;
  }
  int ans = 0;
  for (int i = 0; i < x; i++) {
    vector<array<int,2>> order;
    for (int j = 0; j < n; j++)
      order.push_back({left[j],j});
    sort(order.rbegin(), order.rend());
    cout << "?";
    for (int j = 0; j < k; j++) {
      int ind = order[j][1];
      cout << ' ' << ind+1;
      left[ind]--;
    }
    cout << endl;
    int xo;
    cin >> xo;
    ans ^= xo;
  }
  cout << "! " << ans << endl;
}