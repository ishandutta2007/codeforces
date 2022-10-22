#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll d = 2;
  for (; d*d <= n; d++)
    if (n%d==0) break;
  if (d*d > n) {
    cout << 1 << endl;
    return 0;
  }
  ll c = 1;
  n -= d;
  c += n/2;
  cout << c << endl;
}