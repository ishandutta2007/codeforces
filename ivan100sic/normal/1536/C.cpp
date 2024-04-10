// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct rac {
  ll a, b;

  bool operator< (const rac& o) const {
    return a*o.b < b*o.a;
  }
};


int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    map<rac, int> mp;
    int n;
    string s;
    cin >> n >> s;
    rac t = {0, 0};
    for (char x : s) {
      (x == 'D' ? t.a : t.b)++;
      cout << ++mp[t] << ' ';
    }
    cout << '\n';
  }
}