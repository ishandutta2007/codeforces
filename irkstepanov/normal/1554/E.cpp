#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

const int nmax = 100500;

vector<int> divisors[nmax];

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    for (int i = 1; i < nmax; ++i) {
    	for (int j = 1; j * i < nmax; ++j) {
    		divisors[i * j].pb(i);
    	}
    }

    int tt;
    cin >> tt;
    while (tt--) {
    	int n;
    	cin >> n;
    	vector<vector<int> > g(n);
    	for (int i = 0; i < n - 1; ++i) {
    		int u, v;
    		cin >> u >> v;
    		--u, --v;
    		g[u].pb(v);
    		g[v].pb(u);
    	}
    	vector<int> dp(n + 1, 0);
    	dp[1] = 1;
    	for (int i = 0; i < n - 1; ++i) {
    		add(dp[1], dp[1]);
    	}
    	for (int k : divisors[n - 1]) {
    		if (k == 1) {
    			continue;
    		}
    		queue<int> q;
	    	vector<int> deg(n);
	    	for (int i = 0; i < n; ++i) {
	    		deg[i] = sz(g[i]);
	    		if (deg[i] == 1) {
	    			q.push(i);
	    		}
	    	}

	    	vector<int> c(n);
	    	int killed = 0;
	    	bool ok = true;
	    	while (!q.empty()) {
	    		int v = q.front();
	    		q.pop();
	    		if (killed == n - 1) {
	    			if (c[v] % k) {
	    				ok = false;
	    				break;
	    			}
	    		} else {
	    			if ((c[v] % k) && ((c[v] + 1) % k)) {
	    				ok = false;
	    				break;
	    			}
	    		}
	    		deg[v] = -1;
	    		for (int to : g[v]) {
	    			if (deg[to] != -1) {
	    				--deg[to];
	    				if (c[v] % k == 0) {
	    					++c[to];
	    				}
	    				if (deg[to] == 1) {
	    					q.push(to);
	    				}
	    			}
	    		}
	    		++killed;
	    	}
	    	if (ok) {
	    		dp[k] = 1;
	    	}
    	}
    	vector<int> ans = dp;
    	for (int k = n; k >= 1; --k) {
    		for (int i = 2; k * i <= n; ++i) {
    			sub(ans[k], ans[k * i]);
    		}
    	}
    	for (int k = 1; k <= n; ++k) {
    		cout << ans[k] << " ";
    	}
    	cout << "\n";
    }

}