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

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	vector<int> cnt(n);
    	ll sum = 0;
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    		--a[i];
    		sum += a[i];
    		++cnt[a[i]];
    	}
    	bool valid = true;
    	for (int i = 0; i < n; ++i) {
    		if (cnt[i] != 1) {
    			valid = false;
    		}
    		if (a[i] == i) {
    			valid = false;
    		}
    	}
    	if (valid) {
    		cout << n << "\n";
    		for (int i = 0; i < n; ++i) {
    			cout << a[i] + 1 << " ";
    		}
    		cout << "\n";
    		continue;
    	}

    	int badcnt = 0;
    	int fixed = 0;
    	for (int i = 0; i < n; ++i) {
    		if (cnt[i] >= 2) {
    			++badcnt;
    		}
    		if (a[i] == i) {
    			++fixed;
    		}
    	}

    	bool found = false;

    	for (int i = 0; i < n; ++i) {
    		// change a[i]
    		int x = a[i];
    		--cnt[x];
    		if (cnt[x] == 1) {
    			--badcnt;
    		}
    		if (x == i) {
    			--fixed;
    		}

    		if (fixed == 0 && badcnt == 0) {
    			ll y = ll(n) * (n - 1) / 2 - (sum - x);
    			assert(0 <= y && y < n);
    			if (y != i) {
    				cout << n - 1 << "\n";
    				for (int j = 0; j < n; ++j) {
    					if (i == j) {
    						cout << y + 1 << " ";
    					} else {
    						cout << a[j] + 1 << " ";
    					}
    				}
    				cout << "\n";
    				found = true;
    				break;
    			}
    		}

    		++cnt[x];
    		if (cnt[x] == 2) {
    			++badcnt;
    		}
    		if (x == i) {
    			++fixed;
    		}
    	}

    	if (found) {
    		continue;
    	}

    	vector<vector<int> > g(n);
    	for (int i = 0; i < n; ++i) {
    		if (a[i] != i) {
    			g[a[i]].pb(i);
    		}
    	}

    	int taken = 0;
    	vector<bool> used(n);
    	vector<int> ans(n, -1);
    	for (int i = 0; i < n; ++i) {
    		if (!g[i].empty() && taken < n - 2) {
    			++taken;
    			ans[g[i][0]] = i;
    			used[i] = true;
    		}
    	}

    	int ptr = 0;
    	vector<int> common, lf, rg;
    	for (int i = 0; i < n; ++i) {
    		if (ans[i] == -1 && !used[i]) {
    			common.pb(i);
    		} else if (ans[i] == -1) {
    			lf.pb(i);
    		} else if (!used[i]) {
    			rg.pb(i);
    		}
    	}

    	assert(sz(lf) == sz(rg));

    	if (sz(common) >= 2) {
    		for (int i = 0; i < sz(common); ++i) {
    			int x = common[i];
    			int y = common[(i + 1) % sz(common)];
    			ans[x] = y;
    		}
    		for (int i = 0; i < sz(lf); ++i) {
    			int x = lf[i], y = rg[i];
    			ans[x] = y;
    		}
    	} else if (sz(common) == 1) {
    		assert(sz(lf) > 0);
    		vector<int> p = common;
    		for (int x : lf) {
    			p.pb(x);
    		}
    		vector<int> q = rg;
    		for (int x : common) {
    			q.pb(x);
    		}
    		for (int i = 0; i < sz(p); ++i) {
    			int x = p[i];
    			int y = q[i];
    			ans[x] = y;
    		}
    	} else {
    		for (int i = 0; i < sz(lf); ++i) {
    			int x = lf[i], y = rg[i];
    			ans[x] = y;
    		}
    	}

    	cout << taken << "\n";
    	for (int i = 0; i < n; ++i) {
    		cout << ans[i] + 1 << " ";
    	}
    	cout << "\n";

    }

}