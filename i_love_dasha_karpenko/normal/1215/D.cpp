#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define MODULO 998244353 
#define MAXN 1000000
const ll INF = 10E16;
const ll masksz = 1048576;
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
ll n,summin,summax,sum1min,sum1max;
char A[DIM];
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
	}
	ll resmin = 0, resmax = 0, res1min = 0, res1max = 0,turn = 1;
	forn(i, n / 2) {
		if (A[i] == '?') {
			if (turn == 1) {
				resmax += 9;
				resmin += 0;
			}
			else {
				resmin += 9;
				resmax += 0;
			}
			turn = 3 - turn;
			continue;
		}
		resmin += A[i] - '0';
		resmax += A[i] - '0';
	}
	for (ll i = n / 2 + 1; i <= n; i++) {
		if (A[i] == '?') {
			if (turn == 1) {
				res1max += 0;
				res1min += 9;
			}
			else {
				res1min += 0;
				res1max += 9;
			}
			turn = 3 - turn;
			continue;
		}
		res1min += A[i] - '0';
		res1max += A[i] - '0';
	}
	if (res1min == resmin && res1max == resmax)cout << "Bicarp\n";
	else cout << "Monocarp\n";
	return 0;
}