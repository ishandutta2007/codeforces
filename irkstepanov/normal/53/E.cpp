#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

const int nmax = 13;

int g[nmax][nmax];

ll dp[1 << nmax];

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

ll bin[nmax][nmax];
ll c[nmax];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bin[0][0] = 1;
    for (int i = 1; i < nmax; ++i) {
    	bin[i][0] = 1;
    	for (int j = 1; j < nmax; ++j) {
    		bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
    	}
    }

    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u][v] = g[v][u] = 1;
    }

    c[k] = 1;
    for (int i = k + 1; i <= n; ++i) {
    	ll val = 0;
    	for (int j = k; j < i; ++j) {
    		val += bin[i][j] * c[j];
    	}
    	c[i] = -val;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
    	if (__builtin_popcount(mask) == 1) {
    		dp[mask] = 1;
    		continue;
    	}
    	if (__builtin_popcount(mask) == 2) {
    		vector<int> vct;
    		for (int i = 0; i < n; ++i) {
    			if (bit(mask, i)) {
    				vct.pb(i);
    			}
    		}
    		dp[mask] = g[vct[0]][vct[1]];
    		continue;
    	}
    	for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
    		ll val = dp[mask ^ sub];
    		for (int i = 0; i < n; ++i) {
    			if (!bit(sub, i)) {
    				continue;
    			}
    			int cnt = 0;
    			for (int j = 0; j < n; ++j) {
    				if (!bit(mask, j) || bit(sub, j)) {
    					continue;
    				}
    				if (g[i][j]) {
    					++cnt;
    				}
    			}
    			val *= cnt;
    		}
    		if (__builtin_popcount(sub) % 2 == 0) {
    			val = -val;
    		}
    		dp[mask] += val;
    	}
    }

    ll ans = 0;
    int mask = (1 << n) - 1;

    for (int sub = 1; sub < (1 << n); ++sub) {
    	if (__builtin_popcount(sub) < k) {
    		continue;
    	}
    	ll val = dp[mask ^ sub];
    	for (int i = 0; i < n; ++i) {
    		if (!bit(sub, i)) {
    			continue;
    		}
    		int cnt = 0;
    		for (int j = 0; j < n; ++j) {
    			if (bit(sub, j)) {
    				continue;
    			}
    			if (g[i][j]) {
    				++cnt;
    			}
    		}
    		val *= cnt;
    	}
    	//cout << "!" << sub << " " << val << "\n";
    	ans += val * c[__builtin_popcount(sub)];
    }

    cout << ans << "\n";

}