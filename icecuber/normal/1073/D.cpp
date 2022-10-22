#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll data[1<<19];
ll n = 1<<18;
void add(int i, ll v) {
  i += n;
  while (i) {
    data[i] += v;
    i >>= 1;
  }
}

int myfind(ll v) {
  int i = 1;
  while (i < n) {
    i *= 2;
    if (data[i] <= v) v -= data[i++];
  }
  //cout << data[i] << ' ' << v << endl;
  return i-n;
}

ll a[1<<18];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(i, a[i]);
  }
  ll ans = 0, left = n;
  while (left) {
    ans += (t/data[1])*left;
    t %= data[1];
    int i = myfind(t);
    add(i,-a[i]);
    left--;
  }
  cout << ans << endl;
}