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
ll n,A[DIM],V[DIM];
set<ll> S;
int main() {
	schnell;
	cin >> n;
	ll turn = 1;
	ll num = 1;
	for (ll i = 1; i <= n; i++) {
		if (turn == 1) {
			A[i] = num;
			A[i + n] = num + 1;
		}
		else {
			A[i] = num + 1;
			A[i + n] = num;
		}
		num += 2;
		turn ^= 1;
	}
	ll sum = 0;
	forn(i, n) {
		sum += A[i];
	}
	S.insert(sum);
	ll p = n + 1;
	while(p!=n){
		ll pos = p - n;
		if (pos < 0)pos += n*2;
		sum -= A[pos];
		sum += A[p];
		S.insert(sum);
		p++;
		if (p > 2*n)p -= 2*n;
	}
	if (S.size() > 2) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl; forn(i, n * 2) {
			cout << A[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}