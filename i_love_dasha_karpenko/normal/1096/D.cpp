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
ll n, A[DIM], dp[DIM][6];
string s, t = "hard";
int main() {
	schnell;
	cin >> n;
	cin >> s;
	for (ll i = 0; i < n; i++)cin >> A[i];
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < 4; j++)dp[i][j] = INF;
	}
	dp[0][0] = 0;
	for (ll i = 0; i < n; i++) {

		for (ll j = 0; j < 4; j++) {
			dp[i + 1][j + (s[i] == t[j])] = min(dp[i + 1][j + (s[i] == t[j])], dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + A[i]);
		}
	}
	cout << *min_element(dp[n], dp[n] + 4) << endl;
	return 0;
}