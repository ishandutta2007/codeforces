#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i] >> c[i];
    }
    vi right(n, -1);
    for(int i = 0; i < n; i++) {
    	right[i] = i;
    }
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	swap(v, u);
    	right[v] = max(right[v], u);
    }
    vvi g(n);
    for(int i = 0; i < n; i++) {
    	if(right[i] != -1) {
    		g[right[i]].push_back(i);
    	}
    }
    vvi dp(n + 1, vi(5001, 0));
    for(int i = n - 1; i >= 0; i--) {
    	for(int j = 0; j <= 5000; j++) {
    		dp[i][j] = -INF;
    		if(a[i] > j) {
    			continue;
    		}
    		vi can;
    		int now = j + b[i];
    		for(const auto& u : g[i]) {
    			can.push_back(c[u]);
    		}
    		sort(can.begin(), can.end());
    		reverse(can.begin(), can.end());
    		int score = 0;
    		for(int i1 = 0; i1 <= can.size(); i1++) {
    			if(now - i1 < 0) {
    				break;
    			}
    			if(dp[i + 1][now - i1] != -INF) {
    				dp[i][j] = max(dp[i][j], score + dp[i + 1][now - i1]);
    			}
    			if(i1 != can.size()) {
    				score += can[i1];
    			}
    		}
    	}
    }
    if(dp[0][k] != -INF) {
    	cout << dp[0][k];
    } else {
    	cout << -1;
    }
}