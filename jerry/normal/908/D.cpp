#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll ex(ll a, ll b)
{
	if (!b) return 1;
	ll r = ex(a, b>>1);
	r *= r; r %= MOD;
	if (b&1) { r *= a; r %= MOD; }
	return r;
}

ll k, a, b, inf, y, z, dp[1005][1005];
bool vi[1005][1005];

ll slv(ll A, ll K)
{
	if (K >= k) return K;
	if (A == k) return (inf+A+K)%MOD;
	if (vi[A][K]) return dp[A][K];
	vi[A][K] = true;
	dp[A][K] = (((slv(A+1, K)*a+slv(A, K+A)*b)%MOD)*y)%MOD;
	return dp[A][K];
}

int main()
{
	cin >> k >> a >> b;
	y = ex(a+b, MOD-2);
	z = (a*y)%MOD;
	inf = (z*ex(MOD+1-z, 2*(MOD-2)))%MOD;
	inf *= b; inf %= MOD;
	inf *= y; inf %= MOD;
	cout << slv(1, 0) << endl;
	return 0;
}