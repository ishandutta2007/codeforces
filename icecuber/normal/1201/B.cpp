#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ma = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum += a;
    ma = max(ma, a);
  }
  cout << (ma*2 <= sum && sum%2 == 0 ? "YES" : "NO") << endl;
}