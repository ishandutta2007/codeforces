// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k, q;
string s;
int w[1 << 18];

void pull(int x) {
  if (2*x >= n) {
    w[x] = s[x] == '?' ? 2 : 1;
  } else {
    if (s[x] == '0') w[x] = w[2*x+1];
    else if (s[x] == '1') w[x] = w[2*x];
    else w[x] = w[2*x] + w[2*x+1];
  }
}

void put(int x, char c) {
  s[x] = c;
  while (x > 0) {
    pull(x);
    x >>= 1;
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> k;
  n = 1 << k;
  cin >> s;
  s += 'x';
  reverse(begin(s), end(s));
  for (int i=n-1; i>=1; i--) {
    pull(i);
  }
  cin >> q;
  while (q--) {
    int x;
    char c;
    cin >> x >> c;
    x = n - x;
    put(x, c);
    cout << w[1] << '\n';
  }

}