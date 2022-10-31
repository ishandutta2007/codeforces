#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 200007
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
string s;
ll n, masks[masksz],dp[masksz];
ll popcount(ll mask) {
	ll ret = 0;
	while (mask > 0) {
		ret += mask % 2;
		mask /= 2;
	}
	return ret;
}
int main() {
	schnell;
	cin >> s;
	n = s.length();
	masks[0] = 1;
	for (ll i = 0; i < n; i++) {
		ll mask = 0;
		for (ll j = i; j < n; j++) {
			if ((mask|po(s[j]-'a'))==mask)break;
			mask ^= po(s[j] - 'a');
			masks[mask] = 1;
		}
		
	}
	for (ll i = 0; i < masksz; i++) {
		if (masks[i] == 1) {
			dp[i] = popcount(i); continue;
		}
		for (ll j = 0; j < 20; j++) {
			if ((i | po(j)) == i) {
				dp[i] = max(dp[i], dp[i ^ po(j)]);
			}
		}
	}
	ll res = 0;
	for (ll i = 0; i < masksz; i++) {
		res = max(res, dp[i] + dp[(po(20) - 1) ^ i]);
	}
	cout << res << endl;	
	return 0;
}