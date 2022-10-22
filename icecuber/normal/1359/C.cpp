#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Rat {
  ll p, q;
};

Rat operator-(Rat a, Rat b) {
  return {a.p*b.q-a.q*b.p, a.q*b.q};
}
bool operator<(Rat a, Rat b) {
  ll p = a.p*b.q-a.q*b.p;
  ll q = a.q*b.q;
  return (p < 0 && q < 0) || (p > 0 && q > 0);
}
Rat myabs(Rat a) {
  return {abs(a.p), abs(a.q)};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll h, c, t;
    cin >> h >> c >> t;
    if (t*2 <= h+c) {
      cout << 2 << endl;
    } else {
      ll fail = 2e6, pass = 0;
      while (fail-pass > 1) {
	ll n = (pass+fail)/2;
	ll ap = (n+1)*h+n*c, aq = n*2+1;
	ll bp = (n+2)*h+(n+1)*c, bq = n*2+3;
	ap -= t*aq;
	bp -= t*bq;
	//cout << n << ' ' << ap*1./aq << ' ' << bp*1./bq << ' ' << (abs(ap)*bq <= abs(bp)*aq) << endl;
	if (ap > 0) pass = n;
	else fail = n;
      }
      {
	ll n = pass;
	ll ap = (n+1)*h+n*c, aq = n*2+1;
	ll bp = (n+2)*h+(n+1)*c, bq = n*2+3;
	ap -= t*aq;
	bp -= t*bq;
	if (abs(ap)*bq <= abs(bp)*aq);
	else pass++;
      }
      cout << pass*2+1 << endl;
    }
  }
}