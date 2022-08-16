#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> a(n + 1);
		for(int i = 1; i <= n; i++) cin >> a[i];
		int x; cin >> x;
		if(n==1){
			cout << 1 << endl;
			continue;
		}
		for(int i = 1; i <= n; i++){
			a[i] -= x;
		}
		const int INF = 1 << 20;
		vector<vector<int>> dp(n + 1, vector<int>(4, -INF));
		dp[2][0] = 0;
		dp[2][1] = dp[2][2] = 1;
		if(a[1] + a[2] >= 0) dp[2][3] = 2;
		for(int i = 2; i < n; i++){
			for(int u = 0; u < 4; u++) if(dp[i][u] != -INF){
				int p = u & 1, q = u >> 1;
				bool can = true;
				if(p && a[i] + a[i + 1] < 0) can = false;
				if(p && q && a[i] + a[i + 1] + a[i - 1] < 0) can = false;
				dp[i + 1][2 * p] = max(dp[i + 1][2 * p], dp[i][u]);
				if(can) dp[i + 1][2 * p + 1] = max(dp[i + 1][2 * p + 1], dp[i][u] + 1);
			}
		}
		cout << *max_element(all(dp[n])) << endl;
	}
}