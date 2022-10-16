#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using pii = pair<int, int>;
#define dbg(x) cerr<<#x": "<<(x)<<'\n'
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<'\n';}
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define INF 1000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 5010

int t[500010];
int dp[3][500010];
pii v[500010];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, j, n, k, l0, l1, l2;
	
	cin >> k >> n;
	for(i = 1; i <= n; ++i) cin >> t[i];
	sort(t + 1, t + n + 1);

	for(i = 1; i < n; ++i) {
		v[i] = { t[i], t[i + 1] };
	}
	
	sort(v + 1, v + n, [](pii a, pii b) { return a.y - a.x < b.y - b.x; });
	
	n = min(n - 1, 5 * k);
	sort(v + 1, v + n + 1, [](pii a, pii b) { return a.x < b.x; });
	
	// for(i = 1; i <= n; ++i) cerr << v[i].x << ' ' << v[i].y << '\n';
	
	dp[0][0] = 0;
	for(j = 1; j <= k; ++j) dp[0][j] = INF;
	
	for(l0 = 2, l1 = 0, l2 = 1, i = 1; i <= n; ++i) {
		for(j = 0; j <= k; ++j) {
			dp[l2][j] = dp[l1][j];
			
			if(i > 1 && v[i - 1].y == v[i].x) {
				dp[l2][j] = min(dp[l2][j], dp[l0][j - 1] + v[i].y - v[i].x);
			} else {
				dp[l2][j] = min(dp[l2][j], dp[l1][j - 1] + v[i].y - v[i].x);
			}
		}
		
		l0 = (l0 == 2 ? 0 : l0 + 1);
		l1 = (l1 == 2 ? 0 : l1 + 1);
		l2 = (l2 == 2 ? 0 : l2 + 1);
	}
	
	cout << dp[l1][k] << '\n';
	
	return 0;
}