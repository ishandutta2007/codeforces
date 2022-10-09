// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct mystring {
  string a;
  int l, r, f;
  mystring(string a) : a(a), l(0), r(a.size()), f(0) {}

  void rev(int w) {
    if (w == 1) {
      a[f ? r-1 : l] ^= 1;
    } else if (!f) {
      r = l + w;
      f = 1;
    } else {
      l = r - w;
      f = 0;
    }
  }

  char operator() (int x) {
    if (f) {
      return 1 ^ a[r-1-x];
    } else {
      return a[l+x];
    }
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    mystring c(a);

    basic_string<int> sol;

    for (int k=n; k>=1; k--) {
      if (c(k-1) != b[k-1]) {
        if (c(0) != b[k-1]) {
          c.rev(k);
          sol += k;
        } else {
          c.rev(1);
          c.rev(k);
          sol += {1, k};
        }
      }
    }

    cout << sol.size();
    for (int x : sol) {
      cout << ' ' << x;
    }
    cout << '\n';
  }
}