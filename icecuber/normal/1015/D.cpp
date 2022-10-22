#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, s;
  cin >> n >> k >> s;
  if (s < k || s > (n-1)*k) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  ll base = s/k;
  ll p = 1;
  ll sum = 0;
  for (int i = 0; i < k; i++) {
    ll d = base+(i < s%k);
    sum += d;
    if (i%2 == 0) p += d;
    else p -= d;
    cout << p << ' ';
    assert(p >= 1 && p <= n && d);
  }
  cout << endl;
  assert(sum == s);
}