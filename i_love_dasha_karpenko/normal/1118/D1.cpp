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
#define MODULO 10000000000 
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
ll n, m,sum = 0,A[DIM],P[DIM],C[DIM],S[DIM];
ll Check(ll x) {
	ll r = 0, cn = n / x;

	for (ll i = n; i >= 1; i--) {
		r += max(ll(0), A[i] - (i - 1) / x);
	}
	return r >= m;
}
ll bin(ll L, ll R) {
	while (L != R) {
		ll tm = (L + R) / 2;
		if (Check(tm))R = tm;
		else L = tm + 1;
	}
	return L;
}
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n) {
		cin >> A[i];
		sum += A[i];
	}
	sort(A + 1, A + 1 + n);
	reverse(A + 1, A + 1 + n);
	if (sum < m) {
		cout << -1 << endl;
		return 0;
	}
	cout << bin(1, n) << endl;
	return 0;
}