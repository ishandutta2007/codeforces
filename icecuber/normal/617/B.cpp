#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int last = -1;
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) {
      if (last != -1) ans *= i-last;
      last = i;
    }
  }
  if (last == -1) ans = 0;
  cout << ans << endl;
}