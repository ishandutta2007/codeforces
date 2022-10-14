#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 111;
using ld = long double;
ll n, m, a[maxn];
ld dp[2][maxn*maxn*11], sm[2][maxn*maxn*11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(m==1) {
		cout << 1;
		return 0;
	}
	int S = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], S += a[i];
	memset(dp, 0, sizeof dp);
	memset(sm, 0, sizeof sm);
	cout << fixed << setprecision(2);
	for(int it = 1; it <= n; it++) {
		int i = it&1;
		memset(dp[i^1], 0, sizeof dp[i^1]);
		memset(sm[i^1], 0, sizeof sm[i^1]);
		dp[i][0] = sm[i][0] = 0;
		if(it==1) dp[i][0] = m-1;
		for(int s = 0; s <= n*m; s++) {
			if(it>1)
			dp[i][s] = dp[i][s-1] + sm[i][s];

//			if(dp[i][s] > 0)
//				cout << it << " " << s << " " << dp[i][s] << "\n";
//			for(int cur = 1; cur <= m; cur++) {
//				if(cur==a[it]) continue;
//				dp[i^1][s+cur] += dp[i][s]/(m-1);
//			}
//			cout << s+1 << " " << s+a[it] << " " << s+a[it]+1 << " " << s+m+1 << "\n";
			sm[i^1][s+1]+=dp[i][s]/(m-1);
			sm[i^1][s+a[it]]-=dp[i][s]/(m-1);
			sm[i^1][s+a[it]+1]+=dp[i][s]/(m-1);
			sm[i^1][s+m+1]-=dp[i][s]/(m-1);
		}
//		for(int s = 1; s <= n*m; s++) dp[i^1][s] += dp[i^1][s-1]+sm[i^1][s];
	}
//	for(int s = 1; s <= n*m; s++) dp[(n+1)&1][s] += dp[(n+1)&1][s-1]+sm[(n+1)&1][s];
	ld ans = 1;
	for(int i = 0; i < S; i++)  dp[(n+1)&1][i] =  dp[(n+1)&1][i-1] +  sm[(n+1)&1][i], ans += dp[(n+1)&1][i];
	cout << fixed << setprecision(15) << ans;
}