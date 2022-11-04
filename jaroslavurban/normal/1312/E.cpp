#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define inf 100000000

const ll N = 500;

ll DP[N][N+1];
ll V[N];

ll calcDP(ll l, ll r){
	if (l == r-1)
		return (DP[l][r] = V[l]);
	if (DP[l][r]) return DP[l][r];

	for (ll mid = l+1; mid < r; ++mid){
		ll left = calcDP(l, mid);
		ll right = calcDP(mid, r);
		if (left > 0 && left == right)
			return (DP[l][r] = left + 1);
	}
	return (DP[l][r] = -1);
}


int main(){
	ll n;
	cin >> n;
	ll dp2[N+1];
	dp2[0] = 0;
	for (ll i = 0; i < n; ++i) cin >> V[i];
	for (ll i = 1; i < N; ++i) dp2[i] = inf;
	for (ll i = 0; i < n; ++i)
		for (ll j = i+1; j < n+1; ++j)
			if (calcDP(i, j) > 0)
				dp2[j] = min(dp2[i] + 1, dp2[j]);
	cout << dp2[n] << endl;
}