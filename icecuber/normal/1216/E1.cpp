#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
  n++;
  ll r = 0;
  for (ll m = 1, log10 = 1; ; m *= 10, log10++) {
    if (m*10 <= n) r += log10*m*9;
    else {
      r += (n-m)*log10;
      break;
    }
  }
  return r;
}

ll g(ll n) {
  ll r = (n+1)*f(n);
  n++;
  for (ll m = 1, log10 = 1; ; m *= 10, log10++) {
    if (m*10 <= n) r -= log10*(10*m*(10*m-1)/2-m*(m-1)/2);
    else {
      r -= (n*(n-1)/2-m*(m-1)/2)*log10;
      break;
    }
  }
  return r;
}

ll slowf(ll n) {
  ll r = 0;
  for (int i = 1; i <= n; i++)
    r += to_string(i).size();
  return r;
}

ll slowg(ll n) {
  ll r = 0;
  for (int i = 1; i <= n; i++)
    r += f(i);//slowf(i);
  return r;
}

int main() {
  /*for (int i = 0; i < 10000; i++) {
    assert(f(i) == slowf(i));
    assert(g(i) == slowg(i));
  }
  return 0;*/
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  string s;
  /*for (int i = 1; i < 1000; i++)
    for (int j = 1; j <= i; j++)
      s += to_string(j);
      cerr << s.size() << endl;*/
  while (t--) {
    ll n;
    cin >> n;
    n--;
    //cout << s[n] << endl;
    //continue;
    {
      ll pass = 0, fail = 1e9;
      assert(g(fail) > n);
      while (fail-pass > 1) {
	ll mid = pass+fail>>1;
	if (g(mid) <= n) pass = mid;
	else fail = mid;
      }
      n -= g(pass);
    }
    {
      ll pass = 0, fail = 1e9;
      assert(f(fail) > n);
      while (fail-pass > 1) {
	ll mid = pass+fail>>1;
	if (f(mid) <= n) pass = mid;
	else fail = mid;
      }
      n -= f(pass);
      cout << to_string(pass+1)[n] << endl;
    }
  }
}