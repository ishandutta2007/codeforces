#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, n1, n2, n3;
vvi g;
vector<pair<vi, vi>> comp;
vi c;

bool dfs(int v) {
	for(int u : g[v]) {
		if(c[u] == 0) {
			c[u] = 3 - c[v];
			if(c[u] == 1) {
				comp[comp.size() - 1].first.push_back(u);
			} else {
				comp[comp.size() - 1].second.push_back(u);
			}
			if(!dfs(u)) {
				return false;
			}
		} else if(c[u] == c[v]) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    g.resize(n);
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    c.assign(n, 0);
    for(int i = 0; i < n; i++) {
    	if(c[i] != 0) {
    		continue;
    	}
    	comp.push_back({{}, {}});
    	comp[comp.size() - 1].first.push_back(i);
    	c[i] = 1;
    	if(!dfs(i)) {
    		cout << "NO";
    		return 0;
    	}
    }
    vector<vector<bool>> dp(comp.size() + 1, vector<bool>(n2 + 1, false));
    vector<vector<bool>> prev(comp.size() + 1, vector<bool>(n2 + 1));
    for(int i = 0; i <= comp.size(); i++) {
    	for(int j = 0; j <= n2; j++) {
    		if(i == 0 && j == 0) {
    			dp[i][j] = true;
    			continue;
    		}
    		if(i == 0) {
    			continue;
    		}
    		if(comp[i - 1].first.size() <= j) {
    			if(dp[i - 1][j - comp[i - 1].first.size()]) {
    				dp[i][j] = true;
    				prev[i][j] = false;
    			}
    		}
    		if(comp[i - 1].second.size() <= j) {
    			if(dp[i - 1][j - comp[i - 1].second.size()]) {
    				dp[i][j] = true;
    				prev[i][j] = true;
    			}
    		}
    	}
    }
    //cout << 134 << endl;
    if(!dp[comp.size()][n2]) {
    	cout << "NO";
    	return 0;
    }
    vi ans(n, -1);
    int now = comp.size();
    int now1 = n2;
    while(now != 0) {
    	if(prev[now][now1]) {
    		for(int i = 0; i < comp[now - 1].second.size(); i++) {
    			ans[comp[now - 1].second[i]] = 2;
    		}
    		now1 -= comp[now - 1].second.size();
    		--now;
    	} else {
    		for(int i = 0; i < comp[now - 1].first.size(); i++) {
    			ans[comp[now - 1].first[i]] = 2;
    		}
    		now1 -= comp[now - 1].first.size();
    		--now;
    	}
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
    	if(ans[i] == 2) {
    		cout << 2;
    		continue;
    	}
    	if(n1 > 0) {
    		cout << 1;
    		--n1;
    		continue;
    	}
    	cout << 3;
    }
}