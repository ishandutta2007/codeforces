#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll w, h;
  cin >> w >> h;
  ll ans = 1;
  for (int i = 0; i < w+h; i++)
    (ans *= 2) %= mod;
  cout << ans << endl;
}