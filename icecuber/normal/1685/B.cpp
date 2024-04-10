#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    int as = count(s.begin(), s.end(), 'A');
    int bs = s.size()-as;
    if (as != a+c+d || bs != b+c+d) {
      cout << "NO" << endl;
      continue;
    }
    int x = 0;
    vector<int> A, B;
    int last = 0;
    for (int i = 0; i <= (int)s.size(); i++) {
      if (i == (int)s.size() || (i && s[i] == s[i-1])) {
        if ((last-i)%2) {
          (s[last] == 'A' ? a : b)--;
          x += (i-last)/2;
        } else {
          (s[last] == 'A' ? A : B).push_back((i-last)/2);
        }
        last = i;
      }
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    /*cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    cout << "x: " << x << endl;
    for (int v : A) cout << v << ' '; cout << endl;
    for (int v : B) cout << v << ' '; cout << endl;*/

    while (c && A.size()) {
      int take = min(c,A.back());
      c -= take;
      A.back() -= take;
      if (A.back() == 0) A.pop_back();
    }
    while (d && B.size()) {
      int take = min(d,B.back());
      d -= take;
      B.back() -= take;
      if (B.back() == 0) B.pop_back();
    }
    /*cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    for (int v : A) cout << v << ' '; cout << endl;
    for (int v : B) cout << v << ' '; cout << endl;*/

    int ok = 1;
    if (c && d) {
      ok &= (x >= c+d);
    } else if (!c && !d) {
      ok = 1;
    } else if (!c && d) {
      for (int v : A) {
        d -= v-1;
      }
      ok &= (d <= x);
    } else {
      assert(c && !d);
      for (int v : B) {
        c -= v-1;
      }
      ok &= (c <= x);
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}