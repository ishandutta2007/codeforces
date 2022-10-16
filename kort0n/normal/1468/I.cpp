/**
 *    author:  tourist
 *    created: 25.12.2020 15:44:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  long long vmul = abs(xa * yb - ya * xb);
  if (vmul != n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  set<pair<long long, long long>> s;
  long long d = xa * yb - ya * xb;
  if (d < 0) {
    swap(xa, xb);
    swap(ya, yb);
    d = -d;
  }
  mt19937 rng(58);
  while ((int) s.size() < n) {
    int x = rng() % (int) 1e9;
    int y = rng() % (int) 1e9;
    long long a = x * yb - xb * y;
    long long b = xa * y - x * ya;
    a = (a % d + d) % d;
    b = (b % d + d) % d;
    if (s.find(make_pair(a, b)) == s.end()) {
      cout << x << " " << y << '\n';
      s.emplace(a, b);
    }
  }
  return 0;
}