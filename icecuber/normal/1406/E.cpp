#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  vector<int> primes, isprime(n+1,1);
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (!isprime[i]) continue;
    primes.push_back(i);
    for (int j = i*2; j <= n; j += i)
      isprime[j] = 0;
  }

  vector<int> s(n+1,1);
  s[0] = 0;

  auto local = [&](int p) {
    int r = 0;
    for (int i = p; i <= n; i += p) r += s[i];
    return r;
  };

  auto A = [&](int p) {
    assert(p >= 1 && p <= n);
    cout << "A " << p << endl;
    int r;
    cin >> r;
    int expect = local(p);
    assert(r == expect || r == expect+1);
    return expect != r;
  };
  auto B = [&](int p) {
    assert(p >= 2 && p <= n);
    cout << "B " << p << endl;
    int r;
    cin >> r;
    int expect = local(p);
    for (int i = p; i <= n; i += p) s[i] = 0;
    assert(r == expect || r == expect+1);
    return expect != r;
  };

  set<int> factors;
  int step = 100, first = 1;
  for (int group = 0; group < primes.size(); group += step) {
    for (int i = group; i < group+step && i < primes.size(); i++) {
      int p = primes[i];
      if (B(p)) {
	factors.insert(p);
      }
    }
    if (first && A(1)) {
      first = 0;
      for (int i = group; i < group+step && i < primes.size(); i++) {
	int p = primes[i];
	if (A(p)) {
	  factors.insert(p);
	}
      }
    }
  }

  int ans = 1;
  for (int f : factors) {
    ans *= f;
    for (ll p = (ll)f*f; p <= n; p *= f) {
      if (!A(p)) break;
      ans *= f;
    }
  }
  cout << "C " << ans << endl;
}