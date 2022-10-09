// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct info {
  int l, h, v;

  info() {
    l = h = v = 0;
  }

  info(char c) {
    if (c == '-') {
      l = v = -1;
      h = 0;
    } else if (c == '+') {
      h = v = 1;
      l = 0;
    } else {
      l = h = v = 0;
    }
  }

  info operator+ (const info& b) const {
    info c = b;
    c.l += v;
    c.h += v;
    c.v += v;
    c.l = min(c.l, l);
    c.h = max(c.h, h);
    return c;
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<info> pref(n+1), suff(n+1);

    for (int i=0; i<n; i++) {
      pref[i+1] = pref[i] + info(s[i]);
      suff[i+1] = info(s[n-i-1]) + suff[i];
    }

    while (m--) {
      int l, r;
      cin >> l >> r;
      auto t = pref[l-1] + suff[n-r];
      cout << t.h-t.l+1 << '\n';
    }
  }
}