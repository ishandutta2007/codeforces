    #pragma GCC optimize("trapv")
    #include<bits/stdc++.h>
    #define all(x) x.begin(), x.end()
    #define pb push_back
    using namespace std;
    using ll = long long;
    using vi = vector<ll>;
    using pi = pair<ll, ll>;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const int maxn =5e3 + 55;
    int n, m, k, a[maxn], b[maxn], c[maxn], port[maxn], dp[maxn][maxn];
    vi go[maxn];
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cin >> n >> m >> k;
    	for(int i = 0; i < n; i++)
    		cin >> a[i] >> b[i] >> c[i], port[i] = i;
    	for(int u, v, i = 0; i < m; i++) {
    		cin >> u >> v, u--, v--;
    		port[v] = max(port[v], u);
    	}
    	for(int i = 0; i < n; i++){
    		go[port[i]].pb(i);
    	}
    	for(int i = 0; i < n; i++) {
    		sort(all(go[i]), [&](const int &x, const int &y) {
    			return c[x] > c[y];
    		});
    	}
    	memset(dp, -31, sizeof dp);
    	dp[0][k] = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = a[i]; j <= 5000; j++) {
    			if(dp[i][j]==dp[5011][5011]) continue;
    			int sm = 0;
    			for(int k = 0; k <= j+b[i] && k <= go[i].size(); k++) {
    				dp[i+1][j-k+b[i]] = max(dp[i+1][j-k+b[i]], dp[i][j] + sm);
    				if(k!=go[i].size()) {
    					sm += c[go[i][k]];
    				}
    			}
    		}
    	}
    	int ans = dp[5011][5011];
    	for(int i = 0; i <= 5000; i++)
    		ans = max(ans, dp[n][i]);
    	cout << max(ans, -1);
    }