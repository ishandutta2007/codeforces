//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

ll egcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = egcd(b, a%b, y, x);
	y = a - x*(a/b) - y;
	x = b - x;
	return d;
}

ll inverse(ll a, ll p) {
   ll x,y;
   egcd(a%p + p, p, x, y);
   return x%p;
}

bool crt_error = 0;
ll CRT(ll a, ll m, ll b, ll n) {
	b = (b+n-(a%n))%n;
	ll d = __gcd(m,n);
	if (b%d != 0) { crt_error = 1; return 0; }
	ll old_m = m;
	m/=d; b/=d; n/=d;
	return ((b*inverse(m,n))%n)*old_m + a;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int a, b, p;
  ll x;
  cin >> a >> b >> p >> x;
	ll res = 0;
	ll p2 = 1LL*p*(p-1);
	//if(a == 1) {
	//	res += x/p2;
	//	if(b%p2 <= x%p2) res++;
	//	cout << res << "\n";
	//	return 0;
	//}
  vi W = {1};
  for(int i=1; i<p; i++) {
    W.push_back(1LL * W.back() * a % p);
  }
  assert(W.back() == 1);
	//cerr << (int)W.size() << "\n";
  for(int i=0; i+1<SZ(W); i++) {
    assert(1LL * W[i] * W[SZ(W)-i-1] % p == 1LL);
    int c = 1LL * b * W[SZ(W)-i - 1] % p;
    crt_error = false;
    ll f = CRT(c, p, i, p-1);
		//cerr << i << " " << f << " " << crt_error << "\n";
    if(!crt_error) {
      res += x/p2;
      if(f%p2 <= x%p2) res++;
    }
  }
  cout << res << "\n";
  return 0;
}