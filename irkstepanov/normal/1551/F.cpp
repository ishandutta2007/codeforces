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

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

vector<vector<int> > g;

void dfs(int v, int p, int depth, vector<int>& vct) {
	++vct[depth];
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, depth + 1, vct);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, k;
    	cin >> n >> k;
    	g = vector<vector<int> >(n, vector<int>());
    	for (int i = 0; i < n - 1; ++i) {
    		int u, v;
    		cin >> u >> v;
    		--u, --v;
    		g[u].pb(v);
    		g[v].pb(u);
    	}
    	if (k == 2) {
    		cout << n * (n - 1) / 2 << "\n";
    		continue;
    	}
    	int ans = 0;
    	for (int root = 0; root < n; ++root) {
    		vector<vector<int> > a;
    		for (int to : g[root]) {
    			vector<int> vct(n, 0);
    			dfs(to, root, 1, vct);
    			a.pb(vct);
    		}
    		for (int d = 1; d < n; ++d) {
    			vector<int> sums(k + 1, 0);
    			for (int i = 0; i < sz(a); ++i) {
    				vector<int> nx(k + 1, 0);
    				add(nx[1], a[i][d]);
    				for (int s = 1; s <= k; ++s) {
    					add(nx[s], sums[s]);
    					if (s + 1 <= k) {
    						int val = sums[s];
    						mul(val, a[i][d]);
    						add(nx[s + 1], val);
    					}
    				}
    				sums = nx;
    				/*if (n == 5 && root == 1 && d == 1) {
    					cout << "!" << sums[0] << " " << sums[1] << " " << sums[2] << " " << sums[3] << "\n";
    				}*/
    			}
    			add(ans, sums[k]);
    		}
    	}
    	cout << ans << "\n";
    }

}