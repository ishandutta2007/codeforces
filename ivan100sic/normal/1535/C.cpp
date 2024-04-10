// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void xt(int& x, bool cond) {
  x = cond ? x + 1 : 0;
}

void solve(const string& s) {
  ll z = 0;
  int i = 0, p = 0, q = 0, r = 0;
  for (char x : s) {
    xt(p, x == '0' + i || x == '?');
    xt(q, x == '1' - i || x == '?');
    xt(r, x == '?');
    z += p + q - r;
    i ^= 1;
  }
  cout << z << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    solve(s);
  }
}