#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
#define MODULO 998244353 
const ll MAXN = ll(10E8);
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
ll q, n, A[DIM], B[DIM], dp[DIM][3];
int main() {
	schnell;
	cin >> q;
	forn(ere, q) {
		cin >> n;
		forn(i, n) {
			cin >> A[i] >> B[i];
		}
		dp[1][1] = B[1];
		dp[1][2] = B[1] * 2;

		for (ll i = 2; i <= n; i++) {
			dp[i][0] = INF;
			dp[i][1] = INF;
			dp[i][2] = INF;
			if (A[i] != A[i - 1])dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			if (A[i] != A[i - 1]+1)dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			if (A[i] != A[i - 1]+2)dp[i][0] = min(dp[i][0], dp[i - 1][2]);
			if (A[i] + 1 != A[i - 1])dp[i][1] = min(dp[i][1], dp[i - 1][0] + B[i]);
			if (A[i] + 1 != A[i - 1]+1)dp[i][1] = min(dp[i][1], dp[i - 1][1] + B[i]);
			if (A[i] + 1 != A[i - 1]+2)dp[i][1] = min(dp[i][1], dp[i - 1][2] + B[i]);
			if (A[i] + 2 != A[i - 1])dp[i][2] = min(dp[i][2], dp[i - 1][0] + B[i] * 2);
			if (A[i] + 2 != A[i - 1]+1)dp[i][2] = min(dp[i][2], dp[i - 1][1] + B[i] * 2);
			if (A[i] + 2 != A[i - 1]+2)dp[i][2] = min(dp[i][2], dp[i - 1][2] + B[i] * 2);
		}
		cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
	}

	return 0;
}