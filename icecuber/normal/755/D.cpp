#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template <typename T>
T inv(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  if (k > n-k) k = n-k;

  ll acc = 1, ans = 1;
  for (int i = 0; i < n; i++) {
    if (i) {
      int c = i*k%n, d = (i+1)*k%n;
      if (c > 0 && c < k && d > k ||
	  d > 0 && d < k && c > k) acc++;
    }
    ans += acc;
    cout << ans << ' ';
  }
  cout << endl;
}