#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 1007
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
ll n, m,D[DIM][5];
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n) {
		forn(j, m) {
			char x; cin >> x;
			D[j][x - 'A']++;
		}
	}
	ll res = 0;
	forn(i, m) {
		ll x; cin >> x;
		ll cof = max(max(D[i][0], D[i][1]), max(D[i][2], D[i][3]));
		cof = max(cof, D[i][4]);
		res += x * cof;
	}
	cout << res << endl;
	return 0;
}