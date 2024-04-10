#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  ll k = (a+b)/c;
  cout << k << ' ';
  if (a/c+b/c == k) cout << 0 << endl;
  else cout << c-max(a%c,b%c) << endl;
}