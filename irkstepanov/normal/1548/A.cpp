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

int valid(int i, set<int>& s) {
	if (s.empty() || *(--s.end()) < i) {
		return 1;
	} else {
		return 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<set<int> > g(n);
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u].insert(v);
    	g[v].insert(u);
    }

    vector<int> good(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	good[i] = valid(i, g[i]);
    	if (good[i]) {
    		++ans;
    	}
    }

    int q;
    cin >> q;

    while (q--) {
    	int type;
    	cin >> type;
    	if (type == 3) {
    		cout << ans << "\n";
    	} else {
    		int u, v;
    		cin >> u >> v;
    		--u, --v;
    		if (type == 1) {
    			g[u].insert(v);
    			g[v].insert(u);
    		} else {
    			g[u].erase(v);
    			g[v].erase(u);
    		}
    		int x = valid(u, g[u]);
    		ans += x - good[u];
    		good[u] = x;
    		int y = valid(v, g[v]);
    		ans += y - good[v];
    		good[v] = y;
    	}
    }

}