#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
#define DIM2 DIM*150
#define MODULO 998244353 
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const ll INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
const ld eps = 0.0000001;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}

int main() {
	//schnell;
	ll beg1 = 0, end1 = po(7) - 1;
	ll beg2 = end1 + 1, end2 = po(14) - 1;
	cout << '?' << ' ';
	forn(i, 100) {
		cout << beg1 << ' ';
		beg1++;
	}
	cout << endl;
	ll n1;
	cin >> n1;
	if (n1 == -1)return 0;
	cout << "? ";
	beg2 = 1;
	forn(i, 100) {
		cout << beg2*po(7) << ' ';
		beg2++;
	}
	cout << endl;
	ll n2;
	cin >> n2;
	if (n2 == -1)return 0;
	ll res = 0,mult = 1;
	forn(i, 7) {
		if (n2 & 1)res += mult;
		mult *= 2;
		n2 /= 2;
	}
	forn(i, 7)n1 /= 2;	
	forn(i, 7) {
		if (n1 & 1)res += mult;
		mult *= 2;
		n1 /= 2;
	}
	cout << "! " << res << endl;
	return 0;
}