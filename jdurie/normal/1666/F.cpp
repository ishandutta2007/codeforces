#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define M 998244353
#define N 5010
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll dp[N][N], ct[N], tot[N], n, f[N], fi[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }

#define DP dp[x][e]
ll r(ll x, ll e) {
	if(x < 0) return 1;
	if(!ct[x]) return r(x - 1, e);
	if(~DP) return DP;
	DP = 0;
	if(ct[x] <= e) DP = (DP + NCR(e, ct[x]) * r(x - 1, e - ct[x])) % M;
	ll filled = (tot[x + 1] + e + 1) / 2;
	if(filled < n / 2 && ct[x] <= e + 1) DP = (DP + NCR(e, ct[x] - 1) * r(x - 1, e - ct[x] + 1 + !!filled + (filled == n / 2 - 1))) % M;
	return DP;
}

int main(){
	f[0] = fi[0] = 1;
	F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(tc) while(tc--) {
		cin >> n;
		F(i, 0, n + 1) F(j, 0, n + 1) dp[i][j] = -1;
		F(i, 0, n) { G(x) ct[x]++; }
		for(ll i = n; i; --i) tot[i] = ct[i] + tot[i + 1];
		cout << r(n, 0) << '\n';
		F(i, 1, n + 1) ct[i] = tot[i] = 0;
	}
}