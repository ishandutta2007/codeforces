#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 1000000
#define MS 302
#define BigNumSize 250
#define AddLimit 151
const long INF = 10E16;
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
ll n,A[DIM],res = 0;
int main() {
	schnell;
	cin >> n;
	ll r1 = 0, r2 = 0,r3 = 0;
	forn(i, n) {
		cin >> A[i];
		if (A[i] > 0) {
			r1++; res += A[i] - 1;
		}
		else if (A[i] < 0) {
			r2++;
			res += abs(A[i]) - 1;
		}
		else r3++;
	}
	if (r2 % 2 != 0) {
		if (r3 > 0) {
			r3--;
			res++;
			r2++;
		}
		else {
			res += 2;
			r2--;
		}
	}
	cout << res + r3 << endl;
	return 0;
}