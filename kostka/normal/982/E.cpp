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

// rozwiazuje uklad kongruencji
// x = a (mod m)
// x = b (mod n)
// zwraca res, gdzie x = res (mod nww(m,n))
// zle => ustawia crt_error = 1 (wyzerowac go przed CRT)
bool crt_error = 0;
ll CRT(ll a, ll m, ll b, ll n) {
	b = (b+n-(a%n))%n;
	ll d = __gcd(m,n);
	if (b%d != 0) { crt_error = 1; return 0; }
	ll old_m = m;
	m/=d; b/=d; n/=d;
	return ((b*inverse(m,n))%n)*old_m + a;
}


int w, h, x, y, vx, vy;

pair<ll, ll> loc(ll t, bool print=false) {
  ll nx = x + (1LL*vx*t)%(w*2);
  ll ny = y + (1LL*vy*t)%(h*2);
  nx = (nx+w*2)%(w*2);
  ny = (ny+h*2)%(h*2);
  if(nx>w) nx = w+w-nx;
  if(ny>h) ny = h+h-ny;
  if(print) cout << nx << " " << ny << "\n";
  return {nx, ny};
}

bool good(pair<ll, ll> p) {
  return (p.x == 0 or p.x == w) and (p.y == 0 or p.y == h);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> w >> h >> x >> y >> vx >> vy;
  if(vx == 0) {
    if(good(loc(h-y))) {
      loc(h-y, true);
      return 0;
    }
    if(good(loc(y))) {
      loc(y, true);
      return 0;
    }
  }
  if(vy == 0) {
    if(good(loc(w-x))) {
      loc(w-x, true);
      return 0;
    }
    if(good(loc(x))) {
      loc(x, true);
      return 0;
    }
  }
  int chx = (vx == -1 ? x : w-x);
  int chy = (vy == -1 ? y : h-y);
  auto res = CRT(chx, w, chy, h);
  if(!crt_error and good(loc(res))) {
    loc(res, true);
    return 0;
  }
  cout << -1 << "\n";
  return 0;
}