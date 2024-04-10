#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 998244353  
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};

string buf;
void findr(ll& x, ll& y) {
	char b = 'y';
	while (b=='y') {
		cout << "? " << x << ' ' << y << endl;
		cin >> b;
		x *= 2;
		y *= 2;
	}
	x /= 2;
	y /= 2;
}
ll Ch(ll x) {
	char t;
	cout << "? 0 " << x << endl;
	cin >> t;
	if (t == 'x')return 1;
	return 0;
}
ll bin(ll l, ll r) {
	while (r - l > 1) {
		ll tm = (l + r) / 2;
		cout << "? " << l << ' ' << tm << endl;
		char b; cin >> b;
		if (b == 'e')return 5;
		if (b == 'x') {
			r = tm;
		}
		else {
			l = tm;
		}
	}
	if (Ch(l))return l;
	return r;
	
}
int main() {
	while (1) {
		cin >> buf;
		if (buf != "start")break;
		ll l = 1, r= 2;
		findr(l, r);
		ll k = bin(l, r);
		cout <<"! "<< k << endl;
		
	}
	
	return 0;
}