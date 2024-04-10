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
ll t;

int main() {

	schnell;
	cin >> t;
	forn(e, t) {
		ll n;
		cin >> n;
		ll num = 2;
		while (num * (num + 1) <= 2*n)num++;
		ll c1 = 2*n / (num * (num - 1));
		for(ll i = 0;i<c1;i++) {
			cout << '1';
			//c1--;
		}
		for (ll i = 0; i < num - 2; i++)cout << '3';
		ll dif = n - (c1 * num * (num - 1) / 2);
		for (ll i = 0; i < dif; i++)cout << '1';
		cout << "337\n";
	}
	return 0;
}