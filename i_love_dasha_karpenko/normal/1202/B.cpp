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
struct node {
	ll fi, sc, th;
};
string s;
ll dif[15];
ll gcd(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main() {
	schnell;
	cin >> s;
	ll l = s.length();
	for (ll i = 1; i < l; i++) {
		if (i == 0 && s[i]!='0') {
			dif[s[i] - '0']++; continue;
		}
		ll cf = s[i] - s[i - 1];
		if (cf < 0)cf += 10;
		dif[cf]++;
	}
	for (ll i = 0; i < 10; i++) {
		for (ll j = 0; j < 10; j++) {
			ll r = 0,flag = 0;
			for (ll h = 0; h < 10; h++) {
				if (dif[h] == 0)continue;
				ll F = 0, add = INF;
				for (ll c1 = 0; c1 < 10; c1++) {
					ll cf = (c1 * i) % 10;
					for (ll c2 = 0; c2 < 10; c2++) {
						if (c1 == 0 && c2 == 0)continue;
						ll cf2 = (c2 * j) % 10;
						if ((cf2 + cf) % 10 == h) {
							F = 1;
							add = min(add, c2 + c1);
						}
					}
				}
				if (F == 0) {
					flag = 1;
					break;
				}
				add--;
				r += max(ll(0),add)*dif[h];
			}
			if (flag == 1) {
				cout << -1 << ' ';
				continue;
			}
			cout << r << ' ';
		}
		cout << endl;
	}
	return 0;
}