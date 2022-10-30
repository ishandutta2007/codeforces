#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 20008;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}

ll n,A[DIM];
int main() {
	schnell;
	//cout << -3 / 2 << endl;
	cin >> n;
	ll sum = 0;
	forn(i, n) {
		cin >> A[i];
		sum += A[i] / 2;
		if (A[i]<0 && A[i] % 2 != 0)sum--;
	}
	forn(i, n) {
		ll r = A[i] / 2;
		if (A[i] < 0 && A[i] % 2 != 0)r--;
		if (sum < 0 && A[i]%2!=0) {
			sum++;
			cout << r + 1 << endl;
		}
		else cout <<r << endl;
	}
	cout << endl;
	return 0;
}