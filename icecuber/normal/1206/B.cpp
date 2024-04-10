#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0, zeros = 0, negs = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (!a) zeros++;
    else if (a > 0) ans += a-1;
    else {
      ans += -a-1;
      negs++;
    }
  }
  if (zeros) ans += zeros;
  else if (negs%2 == 1) ans += 2;
  cout << ans << endl;
}