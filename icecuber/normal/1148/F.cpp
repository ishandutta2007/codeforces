#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll,ll>> v(n);
  ll sum = 0;
  for (auto&p : v) {
    cin >> p.x >> p.y;
    sum += p.x;
  }
  if (sum < 0)
    for (auto&p : v)
      p.x = -p.x;

  ll s = 0;
  for (int j = 0; j < 62; j++) {
    ll sum = 0;
    for (auto&p : v)
      if (p.y>>j == 1)
	sum += (__builtin_popcountll(p.y&s)&1?-1:1)*p.x;
    if (sum > 0)
      s |= 1ll<<j;
  }
  cout << s << endl;
}