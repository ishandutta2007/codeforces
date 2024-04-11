//#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,sse2,tune=native,fma")
//#pragma GCC optimize("unroll-loops")
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
const int maxn = 1e2 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int dp[2][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	int t;
	cin >> n;
	int ans = 0;

	for(int i = 0; i < n; i++) {
		cin >> t;
		int u = (i&1)^1;
		dp[i&1][0] = 1+min({dp[u][0], dp[u][1], dp[u][2]});
		if(t&1) dp[i&1][1] = min(dp[u][0], dp[u][2]);
		else dp[i&1][1] = 1<<29;
		if(t&2) dp[i&1][2] = min(dp[u][0], dp[u][1]);
		else dp[i&1][2] = 1<<29;
//		cout  << dp[i&1][0] << " " << dp[i&1][1] << " " << dp[i&1][2] << "\n";
	}
	int u = (n-1)&1;
	cout << min({dp[u][0], dp[u][1], dp[u][2]});
}